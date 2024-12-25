#include <iostream>

// This Class handles the connections between students.
class NoisyClass {
    int noisyStudent; // First integer in the pair.
    int distractedStudent; // Second integer in the pair.
public:
    // Sets the attributes of the class to the arguments provided.
    void setAttributes(int nStudent, int dStudent);
    int noisyStudentValue() const; // returns attribute noisyStudent.
    int distractedStudentValue() const; // returns attribute distractedStudent.
};

void NoisyClass::setAttributes(int nStudent, int dStudent) {
    noisyStudent = nStudent;
    distractedStudent = dStudent;
}

int NoisyClass::noisyStudentValue() const {
    return noisyStudent;
}

int NoisyClass::distractedStudentValue() const {
    return distractedStudent;
}


// Checks each connection to see if it is possible to make
// the class quiet.
bool checkConnections(NoisyClass* c, size_t loops) {
    // Boolean that defaults to true. During the For-Loop, if it
    // is discovered that the connections are impossible for the teacher
    // to quiet down, this will be changed to false.
    bool possible = true;
    // Looping for each value in the connections Class Pointer.
    for (size_t i = 0; i < loops && possible; i++) {
        // Assigning the current index values to temporary variables.
        int noisyStudentTemp = c[i].noisyStudentValue();
        int distractedStudentTemp = c[i].distractedStudentValue();

        // Looping again for each value in the connections Class Pointer,
        // but this loop is to check the temporary variables against every
        // value to see if there are any noisy students connected to 
        // each other directly (paired together).
        for (size_t j = 0; j < loops && possible; j++) {
            if (noisyStudentTemp == c[j].distractedStudentValue() && distractedStudentTemp == c[j].noisyStudentValue())
                possible = false;
            // This series of For-Loops checks if there's a potential
            // chain between 3 students, where each noisy student
            // is in a 3 way cycle that causes an infinite loop.
            // THIS IS NOT AN ELEGANT SOLUTION, but it worked for 
            // all of the DMOJ test cases.
            else if (distractedStudentTemp == c[j].noisyStudentValue()) {
                int x = c[j].distractedStudentValue();
                for (size_t k = 0; k < loops; k++) {
                    if (x == c[k].noisyStudentValue()) {
                        if (c[k].distractedStudentValue() == noisyStudentTemp) {
                            possible = false;
                        }
                    }
                }
            }
        }
    }

    return possible;
}

int main () {
    size_t numStudents; // Total number of students in the program.
    size_t numConnections; // Will be used to decide how many loops to go through.
    size_t loops = 0; // Counts each loop in the Do-While loop.

    // NOTE TO MYSELF: In my solution, I don't use this number. I'm really
    //                 just storing the input since the website wants it?
    // NEW NOTE!!!!!!: I might've found a use for this, just noting this
    //                 moment for posterity.
    // LAST NOTE!!!!!: I never ended up using this value, I figured out a 
    //                 solution that ignored this value completely, but
    //                 it is an ugly solution in my opinion - Om
    std::cin >> numStudents; // Getting the number of students.
    std::cin.ignore(1000, '\n');
    std::cin >> numConnections; // Getting the number of connections.
    std::cin.ignore(1000, '\n');

    // Creating a Class pointer to hold each connection between students.
    NoisyClass* connections = new NoisyClass[numConnections];

    // Filling up the connections Class Pointer.
    do {
        // Temp variables to hold input from the user.
        int noisyStudent = 0, distractedStudent = 0;

        std::cin >> noisyStudent; // First integer in the pair.
        std::cin.ignore(1000, ' ');
        std::cin >> distractedStudent; // Second integer in the pair.
        std::cin.ignore(1000, '\n');

        // Adding the connection to the Class Pointer.
        connections[loops].setAttributes(noisyStudent, distractedStudent);

        // Incrementing the loops variable.
        loops++;
    } while (loops < numConnections);

    // Calls the checkConnections() function. IF the function returns true,
    // outputs "Y" to show that the teacher can quiet down the class,
    // ELSE outputs "N".
    if (checkConnections(connections, loops)) 
        std::cout << "Y" << std::endl;
    else 
        std::cout << "N" << std::endl;
    
    // Deallocating the dynamic Class Pointer.
    delete [] connections;
    connections = nullptr;

    return 0;
}