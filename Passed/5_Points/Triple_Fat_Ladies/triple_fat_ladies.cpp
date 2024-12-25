#include <iostream>
#include <math.h>
#include <string>

int main () {
    unsigned numCases = 0; // The amount of loops to go for.
    unsigned input = 0; // Holds the number inputted by the user for the current test case.
    std::string lastThreeDigits = ""; // Holds the last 3 digits of the cubed number.
    std::string stringCubedInput = ""; // Holds the cubed number as a string.
    unsigned long long int cubedInput = 0; // Holds the inputted number as an unsigned cube.

    // Getting input from the user for the number of test cases.
    std::cin >> numCases;
    std::cin.ignore(1000, '\n');

    // Creating an unsigned array to hold the outputs for the end of the program.
    unsigned* outputs = new unsigned[numCases];

    for (unsigned i = 0; i < numCases; i++) {
        std::cin >> input;
        std::cin.ignore(1000, '\n');
        // Repeatedly cubing the user input until we get to the next possible
        // cubed number that ends in the digits "888".
        do {
            cubedInput = pow(input, 3);
            stringCubedInput = std::to_string(cubedInput);
            if (stringCubedInput.length() > 2) 
                lastThreeDigits = stringCubedInput.substr(stringCubedInput.length() - 3, stringCubedInput.length());
            input += (lastThreeDigits != "888") ? 1 : 0;
        } while (lastThreeDigits != "888");

        // Adding the calculated input value to the outputs array.
        outputs[i] = input;
    }

    // Outputting each value in the outputs array.
    for (unsigned i = 0; i < numCases; i++) {
        std::cout << outputs[i] << std::endl;
    }

    delete [] outputs;
    outputs = nullptr;

    return 0;
}