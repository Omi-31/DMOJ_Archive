#include <iostream>

int main () {
    unsigned long long int scoreToBeat = 0; // Score of the top-scoring-country other than Canada.
    unsigned long long int bronzeMedals = 0; // Canada's bronze medal count.
    unsigned long long int silverMedals = 0; // Canada's silver medal count.
    unsigned long long int goldMedals = 0; // Canada's gold medal count.
    unsigned long long int currentScore = 0; // Canada's current medal score.
    unsigned long long int extraMedalsNeeded = 0; // Potential extra medal count needed for Canada to win.

    // Getting user input for the score of the rival country
    // and each of Canada's current medal counts.
    std::cin >> scoreToBeat >> bronzeMedals >> silverMedals >> goldMedals;

    // Calculating the current score of Canada.
    currentScore = bronzeMedals + (silverMedals * 3) + (goldMedals * 5);

    // Calculating how many extra medals are needed for Canada to win.
    if (scoreToBeat >= currentScore) {
        extraMedalsNeeded = ((scoreToBeat - currentScore) / 5) + 1;
    }

    // Outputting an integer for the amount of extra medals needed for Canada to win.
    std::cout << extraMedalsNeeded << std::endl;

    return 0;
}