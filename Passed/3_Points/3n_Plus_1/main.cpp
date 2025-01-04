#include <iostream>


int main () {
    long long initialValue = 0; // Initial value.
    long long numSteps = 0;

    std::cin >> initialValue; // Getting user input for the initial value.

    // Looping until N == 1;
    while (initialValue != 1) {
        // IF initialValue is ODD, multiply by 3 and then add 1.
        // ELSE divide initialValue by 2.
        initialValue = (initialValue % 2 == 1) ? (initialValue * 3) + 1 : initialValue / 2;
        numSteps++; // Incrementing numSteps each time a loop happens.
    }

    // Outputting numSteps.
    std::cout << numSteps << std::endl;

    return 0;
}