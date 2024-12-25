// This file uses a vector to handle holding the necessary data values
// from the user. This file still gets RTE (bad_alloc) errors when submitting
// to DMOJ.

#include <iostream>
#include <vector>

int main () {
    // This variable is both the number of Spooky Decorations, and
    // the amount of input lines we'll send to the user.
    unsigned numOfDecos = 0;
    // Total houses on the street.
    unsigned numOfHouses = 0;
    // The Spookiness Limit that Kenny will avoid while trick-or-treating.
    unsigned spookinessLimit = 0;
    // This variable tracks the first house that a decoration covers.
    unsigned houseStart = 0;
    // This variable tracks the last house that a decoration covers.
    unsigned houseEnd = 0;
    // This variable holds the user input for the current decoration's spookiness.
    unsigned decoSpookiness = 0;
    // This variable tracks how much candy Kevin has gotten and will be outputted at
    // the end of the program.
    unsigned candyTotal = 0;
    // A Vector that will hold how spooky each individual house is.
    std::vector<unsigned> houseSpookiness;

    // Getting the first line of input.
    std::cin >> numOfDecos; // Decorations on the street.
    std::cin.ignore(1000, ' ');
    std::cin >> numOfHouses; // Total houses.
    std::cin.ignore(1000, ' ');
    std::cin >> spookinessLimit; // The spookiness limit for Kenny.
    std::cin.ignore(1000, '\n');

    // Adding the value 0 to the Vector for each house inputted previously by the user.
    for (unsigned i = 0; i < numOfHouses; i++) {
        houseSpookiness.push_back(0);
    }

    for (size_t i = 0; i < numOfDecos; i++) {
        std::cin >> houseStart; // Where the decoration starts.
        std::cin.ignore(1000, ' ');
        std::cin >> houseEnd; // Where the decoration ends.
        std::cin.ignore(1000, ' ');
        std::cin >> decoSpookiness; // How spooky the decoration is.
        std::cin.ignore(1000, '\n');

        // Subtracting 1 from variable houseStart to account for array's starting at
        // index 0 instead of 1.
        houseStart--;
        houseEnd--;
        // Adding the the spookiness to the houses affected in another For-Loop.
        for (unsigned i = houseStart; i <= houseEnd; i++) {
            houseSpookiness.at(i) += decoSpookiness;
        }
    }

    // A final For-Loop that will calculate how much candy Kevin gets factoring in
    // which houses were too spooky for him to approach.
    for (unsigned i = 0; i < numOfHouses; i++) {
        candyTotal += (houseSpookiness.at(i) < spookinessLimit) ? 1 : 0;
    }

    // Outputting the total candy Kenny was able to get.
    std::cout << candyTotal << std::endl;

    return 0;
}

/*
    LOGIC:
    First Line Of Input: N, L, S
    N = Spooky Decorations on the street.
    L = The number of houses on the street (1 to L).
    S = The limit of Spookiness that Kenny can handle, either equal or greater than.
    a = The first house that the decoration covers.
    b = The last house that the decoration covers.
*/