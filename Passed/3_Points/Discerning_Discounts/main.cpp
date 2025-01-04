#include <iostream>

int main () {
    int numItems = 0; // Number of loops to do.
    double threshold = 0; // Items that Benji will buy after discount.
    double itemCost = 0; // Initial cost of the item.
    double discount = 0; // The discount to apply to the item.
    int itemsPurchased = 0; // The total items purchased by Benji.

    std::cin >> numItems >> threshold; // Getting the number of loops.

    for (int i = 0; i < numItems; i++) {
        std::cin >> itemCost >> discount; // Getting the cost of the item and the discount.
        discount /= 100; // Dividing discount by 100 to turn it into a percentage.

        // Calculating if Benji would purchase the item.
        if (itemCost - (itemCost * discount) <= threshold) {
            itemsPurchased++;
        }
    }

    // Outputting the itemsPurchased.
    std::cout << itemsPurchased << std::endl;

    return 0;
}