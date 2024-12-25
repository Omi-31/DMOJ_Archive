#include <iostream>
#include <string>
#include <list>

int main () {
    // String variable that will hold every input.
    std::string input = "";
    // String list that will hold the values to be outputted at the end of the program.
    std::list<std::string> outputs;
    // Do-While loop that will continue until the user inputs two space characters.
    do {
        std::getline(std::cin, input, '\n');
        if (input != "  ") {
            if (input == "qp" || input == "pq" || input == "db" || input == "bd") 
                outputs.push_back("Mirrored pair");
            else 
                outputs.push_back("Ordinary pair");
        }
    } while (input != "  ");
    
    // First, printing "Ready" to begin the output process, then
    // printing out every value in the outputs list.
    std::cout << "Ready" << std::endl;
    for (std::string i: outputs) {
        std::cout << i << std::endl;
    }
    return 0;
}