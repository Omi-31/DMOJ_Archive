#include <iostream>

int main () {
    int numUsers = 0; // Initial amount of Users (will be multiplied in later calculations).
    int multiplier = 0; // Number used when multiplying numUsers each day.
    int numDays = 0; // Number of loops to do.

    // Getting user input for each variable.
    std::cin >> numUsers;
    std::cin >> multiplier;
    std::cin >> numDays;

    // Calculating the number of users after each contest.
    for (int i = 0; i < numDays; i++) {
        numUsers *= multiplier;
    }

    // Outputting the number of users.
    std::cout << numUsers << std::endl;

    return 0;
}