#include <iostream>

int main () {
    int numLoops = 0; // Number of loops.
    int x = 0; // Holds user input for the X value of the coordinate.
    int y = 0; // Holds user input fro the Y value of the coordinate.

    // Stores the coordinate that is furthest away from 0,0
    int xOutput = 0; 
    int yOutput = 0;

    std::cin >> numLoops;
    std::cin.ignore(1000, '\n');

    // Loops to get each Goose coordinate.
    for (int i = 0; i < numLoops; i++) {
        std::cin >> x >> y;
        std::cin.ignore(1000, '\n');

        if (((x * x) + (y * y)) > ((xOutput * xOutput) + (yOutput * yOutput))) {
            xOutput = x;
            yOutput = y;
        }
    }

    std::cout << xOutput << " " << yOutput << std::endl;

    return 0;
}
