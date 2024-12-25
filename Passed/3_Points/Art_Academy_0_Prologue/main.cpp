#include <iostream>
#include <string>


int main () {
    std::string name = ""; // Holds string input from the user.
    int numLoops = 0; // Number of loops in the For-Loop

    std::cin >> numLoops;
    std::cin.ignore(1000, '\n');

    for (int i = 0; i < numLoops; i++) {
        std::getline(std::cin, name, '\n');
        
        // Going through each character in the string, and printing
        // out the relevant response.
        for (char x : name) {
            if (x == 'A' || x == 'a') 
                std::cout << "Hi! ";
            else if (x == 'E' || x == 'e') 
                std::cout << "Bye! ";
            else if (x == 'I' || x == 'i')
                std::cout << "How are you? ";
            else if (x == 'O' || x == 'o')
                std::cout << "Follow me! ";
            else if (x == 'U' || x == 'u')
                std::cout << "Help! ";
            else if (isdigit(x)) 
                std::cout << "Yes! ";
        }
        // Outputting a newline at the end of the string reading.
        std::cout << std::endl;
    }

    return 0;
}