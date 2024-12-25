#include <iostream>
#include <string>
#include <sstream>


int main () {
    std::string inputString = "";
    int numNots = 0;
    std::getline(std::cin, inputString, '\n');
    
    if (!inputString.empty()) {
        std::stringstream s(inputString);

        while (s >> inputString) {
            if (inputString == "not")
                numNots++;
        }

        if (inputString == "True") {
            if (numNots % 2 == 0) {
                std::cout << "True" << std::endl;
            } else {
                std::cout << "False" << std::endl;
            }
        } else {
            if (numNots % 2 == 0) {
                std::cout << "False" << std::endl;
            } else {
                std::cout << "True" << std::endl;
            }
        }
    }

    return 0;
}