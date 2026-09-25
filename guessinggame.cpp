#include <iostream>
#include <random>

int main() {
    int difficult_level;
    int input;
    int guess;
    int chance;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::cout << "==== Random Number Generator Game ====\n";

    std::cout << "Choose your difficulty:\n";
    std::cout << "1. Easy (0-50)\n";
    std::cout << "2. Medium (0-500)\n";
    std::cout << "3. Hard (0-5000)\n";

    std::cout << "Enter your choice (1,2,3): ";
    std::cin >> difficult_level;

    if (difficult_level == 1) {
        std::uniform_int_distribution<int> distrib(0, 50);
        guess = distrib(gen);
        chance = 10;
    } else if (difficult_level == 2) {
        std::uniform_int_distribution<int> distrib(0, 500);
        guess = distrib(gen);
        chance = 7;
    } else if (difficult_level == 3) {
        std::uniform_int_distribution<int> distrib(0, 5000);
        guess = distrib(gen);
        chance = 5;
    } else {
        std::cout << "Wrong input!\n";
        return 0;
    }
    
    do {
        // my main code
        std::cout << "Enter Your Number : ";
        std::cin >> input;

        // now, I will run if-else loop
        if ( guess != input){
            std::cout << "You disappointed me!" << '\n';

            // Hint System
            if (input > guess){
                std::cout << "Too High! Where are you going ? " << '\n';
            } else {
                std::cout << "Low! Low! Try bro....try bigger!! " << '\n';
            }
            chance--;

            std::cout << "Attempts left: " << chance << '\n';
            if (chance == 0){
                std::cout << "You ran out of chances!!" << '\n';
            }
        } else {
            std::cout << "You guessed it right!" << '\n';
        }
    }

    while (guess != input && chance > 0);
    return 0;
}