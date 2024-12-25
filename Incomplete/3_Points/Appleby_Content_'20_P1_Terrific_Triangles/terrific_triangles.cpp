#include <iostream>
#include <list>
#include <math.h>

int main () {
    int numQuestions = 0; // The number of loops the program will go through.
    // Variables to hold all the side lengths.
    unsigned side1 = 0;
    unsigned side2 = 0;
    unsigned side3 = 0;
    // List to hold the char outputs for the end of the program.
    std::list<char> triangleOutputs;

    std::cin >> numQuestions;
    std::cin.ignore(1000, '\n');

    // Looping for each question the user specified.
    for (int i = 0; i < numQuestions; i++) {
        // Getting all 3 side inputs.
        std::cin >> side1;
        std::cin.ignore(1000, ' ');
        std::cin >> side2;
        std::cin.ignore(1000, ' ');
        std::cin >> side3;
        std::cin.ignore(1000, '\n');
        // Squaring all the sides.
        side1 = pow(side1, 2);
        side2 = pow(side2, 2);
        side3 = pow(side3, 2);
        std::cout << side1 << " " << side2 << " " << side3 << " " << std::endl;
        // side1 is larger than side2 and side3.
        if (side1 > side2 && side1 > side3) {
            if (side1 > (side2 + side3)) triangleOutputs.push_back('O');
            else if (side1 == (side2 + side3)) triangleOutputs.push_back('R');
            else triangleOutputs.push_back('A');
        // side2 is larger than side1 and side3.
        } else if (side2 > side1 && side2 > side3) {
            if (side2 > (side1 + side3)) triangleOutputs.push_back('O');
            else if (side2 == (side1 + side3)) triangleOutputs.push_back('R');
            else triangleOutputs.push_back('A');
        // side3 is larger than side2 and side1.
        } else {
            if (side3 > (side2 + side1)) triangleOutputs.push_back('O');
            else if (side3 == (side2 + side1)) triangleOutputs.push_back('R');
            else triangleOutputs.push_back('A');
        }
    }
    
    // Outputting letters for each triangle.
    for (char i: triangleOutputs) {
        std::cout << i << std::endl;
    }

    return 0;
}