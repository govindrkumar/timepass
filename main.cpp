#include <iostream>
#include <string>
#include <filesystem>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <random>

namespace fs = std::filesystem;

// calculator
void calculator() {
    double a;
    double b;
    std::string operations;

    std::cout << "GCalc\n";
    std::cout << "Only two numbers(Type with spaces)\n\n";

    while (true) {
        std::cout << "calc> ";
        std::cin >> a >> operations >> b;

        if (operations == "+") {
            std::cout << a + b << std::endl;
        }
        else if (operations == "-") {
            std::cout << a - b << std::endl;
        }
        else if (operations == "*") {
            std::cout << a * b << std::endl;
        }
        else if (operations == "/") {
            std::cout << a / b << std::endl;
        }
        else if (operations == "%") {
            double result = std::fmod(a, b);
            std::cout << result << std::endl;
        }
    }
}

void mkdir(std::string fsName) {
    if (fsName.length() >= 6 &&
        fsName[0] == 'm' &&
        fsName[1] == 'k' &&
        fsName[2] == 'd' &&
        fsName[3] == 'i' &&
        fsName[4] == 'r' &&
        fsName[5] == ' ') {

        std::string name;

        for (int i = 6; i < fsName.length(); i++) {
            name.push_back(fsName[i]);
        }

        fs::create_directory(name);
    }
}

void numgame(){
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
    return;
}

int main() {
    std::cout << "Welcome to GS Shell\n";

    std::string UserName;
    std::cout << "Enter Username : ";
    std::cin >> UserName;
    std::cin.ignore();

    std::cout << "Hi " << UserName << std::endl;
    std::cout << "Welcome to GS File Manager!!\n\n";

    while (true) {
        std::string commands;

        std::cout << "gfm> ";
        std::getline(std::cin, commands);

        if (commands == "hello") {
            std::cout << "Hi, " << UserName << "!" << std::endl;
        }
        else if (commands == "whoami") {
            std::cout << UserName << std::endl;
        }
        else if (commands == "exit") {
            exit(0);
        }
        else if (commands == "pwd") {
            std::cout << fs::current_path() << std::endl;
        }
        else if (commands == "ls") {
            for (const auto& entry : fs::directory_iterator(".")) {
                std::cout << entry.path() << '\n';
            }
        }
        else if (commands == "tree") {
            std::system("tree");
        }
        else if (commands == "calc" || commands == "calculator") {
            calculator();
        }
        else if (commands.length() >= 5 &&
                 commands[0] == 'm' &&
                 commands[1] == 'k' &&
                 commands[2] == 'd' &&
                 commands[3] == 'i' &&
                 commands[4] == 'r') {
            mkdir(commands);
        }
        else if (commands == "numgame" || commands == "ng"){
            numgame();
        }
        else if (commands == "clear"){
            std::system("clear");
        }
        else {
            std::cout << commands << " is not available." << std::endl;
        }
    }

    return 0;
}

