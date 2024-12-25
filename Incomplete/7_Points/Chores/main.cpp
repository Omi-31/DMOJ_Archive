// Time Limit Exceeded Issue. Not sure how to proceed from here.

#include <iostream>
#include <stdio.h>
#include <list>

struct Chores {
    unsigned choreTime;
    unsigned choreAmount;
};

int main () {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    // The amount of loops to do in the For-Loop.
    int numberOfLines = 0;
    // Vector to hold Chores objects.
    std::list<Chores> numberOfChores;
    // Struct value to get input from the user.
    Chores choreInput;
    // Unsigned variable to hold the minimum efficiency score.
    unsigned long long int efficiency = 0;
    // Unsigned variable to hold the current time on the stopwatch (minutes).
    unsigned long long int stopwatch = 0;
    // Tracks the largest chore time to complete.
    unsigned long long int largestChoreTime = 0;
    // Tracks the smallest chore time to complete.
    unsigned long long int smallestChoreTime = 1000000000;
    // Tracks if we need to scan the entire vector to see where to place
    // the struct object properly.
    bool notSmallestOrBiggest = true;

    std::cin >> numberOfLines;
    std::cin.ignore(1000, '\n');

    // Looping to get each chore time, and chore amount.
    for (int i = 0; i < numberOfLines; i++) {
        notSmallestOrBiggest = true;

        std::cin >> choreInput.choreTime;
        std::cin.ignore(1000, ' ');
        std::cin >> choreInput.choreAmount;
        std::cin.ignore(1000, '\n');

        if (choreInput.choreTime >= largestChoreTime) {
            largestChoreTime = choreInput.choreTime;
            numberOfChores.push_back(choreInput);
            notSmallestOrBiggest = false;
        } else if (choreInput.choreTime <= smallestChoreTime) {
            smallestChoreTime = choreInput.choreTime;
            numberOfChores.push_front(choreInput);
            notSmallestOrBiggest = false;
        }

        if (notSmallestOrBiggest) {
            bool flag = true;
            for (std::list<Chores>::iterator it = numberOfChores.begin(); it != numberOfChores.end() && flag; it++) {
                if (choreInput.choreTime <= it->choreTime) {
                    numberOfChores.emplace(it, choreInput);
                    flag = false;
                }
            }
        }
    }

    for (std::list<Chores>::iterator it = numberOfChores.begin(); it != numberOfChores.end(); it++) {
        for (unsigned i = 0; i < it->choreAmount; i++) {
            stopwatch += it->choreTime;
            efficiency += stopwatch;
        }
    }
    
    std::cout << efficiency % (1000000000 + 7) << "\n";

    return 0;
}