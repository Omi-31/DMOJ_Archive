#include <iostream>
#include <vector>

// Holds each task provided to us and when to do them.
struct instructions {
    int task; // A number ranged 1-7.
    int toDoBeforeNum; // The number that the current task should be done before.
};

struct taskTracker {
    int task; // A number ranged 1-7.
    int numPrerequisites; // How many instructions are related to the task.
};

// Function Declarations to check the connections between instruction pairs.
bool checkConnections(std::vector<instructions> pairs, instructions initialTask);
bool checkConnections(std::vector<instructions> pairs, instructions initialTask, instructions connectedTask, bool& result);


// Function Bodys:
bool checkConnections(std::vector<instructions> pairs, instructions initialTask) {
    bool result = true;

    for (unsigned i = 0; i < pairs.size() && result; i++) {
        if (pairs.at(i).task == initialTask.toDoBeforeNum) {
            // If there is a potential connection between tasks, further validation
            // is done to see if the tasks are conflicting.
            result = checkConnections(pairs, initialTask, pairs.at(i), result);
        } 
    }

    return result;
}

bool checkConnections(std::vector<instructions> pairs, instructions initialTask, instructions connectedTask, bool& result) {
    for (unsigned i = 0; i < pairs.size() && result; i++) {
        if (pairs.at(i).task == connectedTask.toDoBeforeNum) {
            if (pairs.at(i).task == initialTask.toDoBeforeNum) {
                result = false;
            } else if (pairs.at(i).task == connectedTask.toDoBeforeNum && pairs.at(i).task != connectedTask.task) {
                if (pairs.at(i).toDoBeforeNum == initialTask.task) {
                    result = false;
                } else {
                    result = checkConnections(pairs, initialTask, pairs.at(i), result);
                }
            }
        }
    }

    return result;
}
// Checks how many prerequisites there are for each task, storing the value
// in an integer.
void checkPrerequisites(std::vector<instructions> pairs, std::vector<taskTracker>& taskTracker) {
    // Loops for each value in the "pairs" vector.
    for (unsigned i = 0; i < taskTracker.size(); i++) {
        if (taskTracker.at(i).task != -1) {
            taskTracker.at(i).numPrerequisites = 0;
        }
    }
    for (unsigned i = 0; i < pairs.size(); i++) {
        for (unsigned j = 0; j < taskTracker.size(); j++) {
            if (pairs.at(i).toDoBeforeNum == taskTracker.at(j).task) {
                taskTracker.at(j).numPrerequisites++;
                j = taskTracker.size();
            }
        }
    }
}

void print(std::vector<instructions> pairs) {
    // The order of importance is 2, 1, 3, 4, 5, 6, 7. This is the order that
    // I will be going through for the output.
    // List of tasks to go through.
    std::vector<int> taskList = {2, 1, 3, 4, 5, 6, 7};
    // A vector to track how many prerequisites each task has before it can be completed.
    std::vector<taskTracker> taskTracker = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}};
    // Int array to hold the order of tasks to be completed for the output.
    int output[7] = {-1, -1, -1, -1, -1, -1, -1};
    int index = 0; // Tracks the index of the "output" array so number's are not improperly added.

    bool alreadyChecked = false; // Variable to check if the checkPrerequisites() function has been called.
    int i = 0;
    // Looping until the vector "taskList" is cleared out.
    while (index < 7) {
        if (!alreadyChecked) {
            checkPrerequisites(pairs, taskTracker);
            alreadyChecked = true;
        }
        // IF a task can be completed safely.
        if (taskTracker.at(i).task != -1 && taskTracker.at(i).numPrerequisites == 0) {
            output[index] = taskTracker.at(i).task; // Adds the task to the "output" array.
            // For-Loop to remove the added task from the "pairs" vector.
            for (unsigned j = 0; j < pairs.size(); j++) {
                if (taskTracker.at(i).task == pairs.at(j).task) {
                    pairs.at(j).task = -1;
                    pairs.at(j).toDoBeforeNum = -1;
                }
            }
            index++;
            alreadyChecked = false;
            taskTracker.at(i).task = -1; // Sets the task in the vector to -1 to clear it.
            taskTracker.at(i).numPrerequisites = -1; // Sets the prerequisites to -1 so it's skipped in the future.
            i = 0;
        } else {
            i++;
        }
    }

    for (int i = 0; i < 7; i++) {
        if (i < 6) 
            std::cout << output[i] << " ";
        else
            std::cout << output[i] << std::endl;
    }


}

int main () {
    // A vector of the struct defined earlier that can dynamically hold each task
    // in the list specified. It is initialized with the original instructions
    // provided to us by our Mom.
    std::vector<instructions> pairs = {{2, 1}, {1, 4}, {1, 7}, {3, 4}, {3, 5}};
    // struct value that will be pushed to the "pairs" vector.
    instructions temp;

    // Do-While loop until both int inputs = 0.
    do {
        // Getting integer input from the user.
        std::cin >> temp.task;
        std::cin.ignore(1000, '\n');
        std::cin >> temp.toDoBeforeNum;
        std::cin.ignore(1000, '\n');

        // Pushing the struct "temp" to the vector "pairs" if 
        // both integers are not 0.
        if (temp.task != 0 && temp.toDoBeforeNum != 0) {
            pairs.push_back(temp);
        }
    } while (temp.task != 0 && temp.toDoBeforeNum != 0);

    // Boolean that will track if the list of tasks is even completable.
    bool possible = true;

    // Looping to check every connection between tasks.
    for (unsigned i = 0; i < pairs.size() && possible; i++) {
        possible = checkConnections(pairs, pairs.at(i));
    }

    if (possible) 
        print(pairs);
    else
        std::cout << "Cannot complete these tasks. Going to bed." << std::endl;
    

    return 0;
}

/* 
LOGIC:
The correct sequencing with no additional instructions:
- 2 (Call Grandma)
- 1 (Do Homework) NOTE: 1 and 3 can both be completed, but 1 is the lower number.
- 3 (Call Mom)
- 4 (Call Friend)
- 5 (Feed Dog)
- 6 (Let Dog Out)
- 7 (Watch Television)
*/