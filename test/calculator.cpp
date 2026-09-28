#include <iostream>
#include <string>
#include <filesystem>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <random>

int main(){
    double a;
    double b;
    double result = 0;
    double stored_result;
    std::string operations;

    while (true){
        std::cout << "calc> ";
        std::cout << "Enter the number: ";
        std::cin >> a;

        std::cout << "calc> Enter operation: ";
        std::cin >> operations;

        std::cout << "calc> Enter second number: ";
        std::cin >> b;

        

        if (operations == "+"){
            result = a + b;
        } else if (operations == "-"){
            result = a - b;
        } else if (operations == "*"){
            result = a * b;
        } else if (operations == "/"){
            result = a / b;
        }

        std::cout << "Result: " << result << std::endl;
        std::string decision;
        std::cout << "Continue? (Type Y/yes/y/no/exitc): ";
        std::cin >> decision;

        if (decision == "exitc"){
            return 0;
        }  else if{
            continue;
        }
    }
}