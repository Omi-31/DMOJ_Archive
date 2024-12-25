#include <iostream>
#include <string>

int main() {
    // For the for loop that outputs the data.
    size_t noOfLoops = 0;
    // This string will handle the line input, we will extract the 
    // integer from the string that decides which character to remove.
    std::string input = "";
    // This number will be extracted from the string input later
    // in the program, initializing to a safe state at start of run-time.
    size_t charToRemove = -1;
    // String array to hold each converted word, to be used when printing
    // out each line.
    std::string arr[1000];

    // Getting the amount of loops from the user, and ignoring
    // the newline character.
    std::cin >> noOfLoops;
    std::cin.ignore(1000, '\n');

    for (size_t i = 0; i < noOfLoops; i++) {
        // Getting the full input line that has the integer and word.
        std::getline(std::cin, input, '\n');
        // Converting the string integer into a size_t variable. First, we're
        // checking to see how big the string variable actually is. Then, 
        // we're using the index value we find in combination with substr and
        // stoi to convert the string integer into a size_t variable.
        size_t indexOfInt = 0;
        for (size_t j = 0, flag = 1; j < input.length() && flag == 1; j++) {
            if (input[j] == ' ') {
                flag = 0;
            } else indexOfInt++;
        }
        charToRemove = std::stoi(input.substr(0, indexOfInt));

        // Removing the integer from the start of the string variable.
        input = input.substr(indexOfInt + 1, input.length() - 1);
        // Creating a new std::string that will hold the converted word with the 
        // character removed. The character is removed by using substr around the 
        // index of charToRemove.
        std::string temp = input.substr(0, charToRemove - 1);
        temp += input.substr(charToRemove, input.length() - 1);
        // Setting the original input string to the temp string, because temp
        // will not be accessible outside of the For-Loop scope when we try
        // printing the output in a different For-Loop.
        input = temp;
        // Adding each input to the pre-defined std::string array.
        arr[i] = input;
    }
    // Outputting each updated string value.
    for (size_t i = 0; i < noOfLoops; i++) {
        std::cout << i + 1 << " " << arr[i] << std::endl;
    }

    return 0;
}