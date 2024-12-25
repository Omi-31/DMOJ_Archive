#include <iostream>
#include <string>

int main () {
    std::string input = "";
    // Counting the number of TAKEs and SERVEs.
    int numTake = 0, numServe = 0, currentNum = 0;
    bool lastLine = false;

    // Input for what the current number is.
    std::cin >> currentNum;
    std::cin.ignore(1000, '\n');

    // Do-While loop to go through each input.
    do {
        // Using getline to get the string input from the user.
        std::getline(std::cin, input, '\n');

        if (input == "TAKE") {
            numTake++;
            currentNum++;
            // If the 999th ticket has been taken by a student, the current
            // ticket number is reset to 0.
            currentNum = (currentNum > 999) ? 1 : currentNum;
        }
        // Incrementing numServe for every student that has been served.
        numServe += (input == "SERVE") ? 1 : 0;

        // When input is "CLOSE", all data values will be outputted in order of
        // numTake, numServe, and then currentNum.
        if (input == "CLOSE") {
            // Outputting number of late students.
            std::cout << numTake << " ";
            // Outputting the number of students still waiting in the line.
            std::cout << numTake - numServe << " ";
            // Outputting the current ticket number on the roll of tickets.
            std::cout << currentNum << std::endl;

            // Resetting the numTake and numServe variables, but keeping the currentNum tracker
            // for future students.
            numTake = 0;
            numServe = 0;
        }
        // lastLine becomes true if the input reads "EOF", and then the Do-While loop will end.
        lastLine = (input == "EOF") ? true : false;

    } while (!lastLine);


    return 0;
}

