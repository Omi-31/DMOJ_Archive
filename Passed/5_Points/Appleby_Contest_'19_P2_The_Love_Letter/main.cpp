#include <iostream>
#include <string>

int main () {
    int stringLength = 0; // Length of the string.
    int shift = 0; // The shift value to apply to the Caesar.
    std::string inputString = ""; // Holds the string input from the user.

    // Getting the length of the string from the user.
    std::cin >> stringLength;
    std::cin.ignore(1000, '\n');
    // Getting the value to shift the string from the user.
    std::cin >> shift;
    std::cin.ignore(1000, '\n');
    shift %= 26;
    // Getting the full string from the user.
    std::getline(std::cin, inputString, '\n');

    for (char x : inputString) {
        if (x != ' ') {
            if (int(x) + shift > 122) {
                x -= 26;
                x += shift;
            } else {
                x += shift;
            }
        }
        std::cout << x;
    }

    return 0;
}