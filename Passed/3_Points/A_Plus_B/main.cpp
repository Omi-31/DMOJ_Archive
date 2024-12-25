#include <iostream>


int main () {
    int numLoops = 0;
    int x = 0;
    int y = 0;

    std::cin >> numLoops;
    std::cin.ignore(1000, '\n');

    int* output = new int[numLoops];

    for (int i = 0; i < numLoops; i++) {
        std::cin >> x >> y;
        std::cin.ignore(1000, '\n');

        output[i] = x + y;
    }

    for (int i = 0; i < numLoops; i++) {
        std::cout << output[i] << std::endl;
    }

    delete [] output;
    output = nullptr;

    return 0;
}