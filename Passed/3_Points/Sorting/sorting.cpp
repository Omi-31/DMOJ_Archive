#include <iostream>
#include <forward_list>

int main () {
    std::forward_list<int> numberList; // forward_list of numbers that will be sorted later.
    int loops = 0;
    int input = 0; // variable that will hold the numbers the user inputs.

    std::cin >> loops; // First, getting a number that decides how many loops to go for.
    std::cin.ignore(1000, '\n');

    // Filling up the forward_list with numbers from the user.
    for (int i = 0; i < loops; i++) {
        std::cin >> input;
        std::cin.ignore(1000, '\n');

        numberList.push_front(input);
    }
    // Sorting the forward_list using the predefined function sort().
    numberList.sort();

    // Printing out each element of the forward_list on a newline.
    for (int i: numberList) {
        std::cout << i << std::endl;
    }

    return 0;
}