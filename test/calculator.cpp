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
    double stored_result = 0;
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
        }
        else if (decision == "yes" || decision == "y" || decision == "Y"){
            stored_result += result;
            do {
                        std::cout << "calc> Enter the operation: ";
                        std::cin >> operations;

                        // now....let's see
                        std::cout << "calc> Enter the second number: ";
                        std::cin >> b;

                        if (operations == "+"){
                            stored_result += b;
                        } else if (operations == "-"){
                            stored_result -= b;
                        } else if (operations == "*"){
                            stored_result *= b;
                        } else if (operations == "/"){
                            stored_result /= b;
                        }
                        std::cout << "Result: " << stored_result << std::endl;
                        std::cout << "Continue?: ";
                        std::cin >> decision;
                    
            }
            while (decision == "yes" || decision == "y" || decision == "Y");
        }
        else {
            continue;
        }
    }
}