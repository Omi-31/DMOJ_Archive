#include <iostream>
#include <iomanip>

int main () {
    size_t initialStudents = 0; // Number of students in the class initially.
    size_t transferStudents = 0; // Number of students transferring into the class.

    std::cin >> initialStudents; // Getting input for the value of initialStudents.
    std::cin.ignore(1000, '\n');

    // Allocating memory to hold each initial student's mark.
    int* initialStudentMarks = new int[initialStudents];
    
    // Looping to get input for each initial student's mark.
    for (size_t i = 0; i < initialStudents; i++) {
        std::cin >> initialStudentMarks[i];
        std::cin.ignore(1000, '\n');
    }

    // Getting input for the value of transferStudents.
    std::cin >> transferStudents;
    std::cin.ignore(1000, '\n');

    // Adding the initial amount of students to the transfer student amount.
    transferStudents += initialStudents;
    // Alocating memory to hold each transfer student's mark.
    int* transferStudentMarks = new int[transferStudents];
    // Adding the initial student marks to the transfer student array.
    for (size_t i = 0; i < initialStudents; i++) {
        transferStudentMarks[i] = initialStudentMarks[i];
    }

    // Looping to get input for each transfer student's mark.
    for (size_t i = initialStudents; i < transferStudents; i++) {
        std::cin >> transferStudentMarks[i];
        std::cin.ignore(1000, '\n');
    }

    // Local variable to hold the sum of the marks array..
    double result = 0;
    // Adding the amount of marks from the transferStudentArray.
    for (size_t i = 0; i < transferStudents; i++) {
        result += transferStudentMarks[i];
        if ((i + 1) > initialStudents) {
            
            // Outputting the result, set to 3 decimal points.
            std::cout << std::fixed << std::setprecision(3) << result / (i + 1) << std::endl;
        }
    }
    
    // Deallocating dynamic memory.
    delete [] initialStudentMarks;
    initialStudentMarks = nullptr;

    delete [] transferStudentMarks;
    transferStudentMarks = nullptr;

    return 0;
}