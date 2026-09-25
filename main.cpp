#include <iostream>
#include <string>
#include <filesystem>
#include <cmath>
#include <cstdlib> // I will use std::system by this....
namespace fs = std::filesystem;

// My main function....
void calculator(){
    double a;
    double b;
    std::string operations;

    std::cout << "GCalc\n";
    std::cout << "Only two numbers(Type with spaces)\n\n";

    while (true) {
        std::cout << "calc> ";
        std::cin >> a >> operations >> b;

        if (operations == "+"){
            std::cout << a + b << std::endl;
        } else if (operations == "-"){
            std::cout << a - b << std::endl;
        } else if (operations == "*"){
            std::cout << a * b << std::endl;
        } else if (operations == "/"){
            std::cout << a / b << std::endl;
        } else if (operations == "%"){
            double result = std::fmod(a , b);
            std::cout << result << std::endl;
        }
    }
}

int main() {
    std::cout << "Welcome to GS File Manager!\n";

    std::string UserName;
    std::cout << "Enter Username : ";
    std::cin >> UserName;
    std::cout << "Hi " << UserName << std::endl;
    std::cout << "Welcome to GS File Manager!!\n\n";

    while (true){
        // now.....main things
        std::string commands;
        std::cout << "gfm> ";
        std::cin >> commands;

        if (commands == "hello"){
            std::cout << "Hi, " << UserName << "!" << std::endl;
        }
        else if (commands == "whoami"){
            std::cout << UserName << std::endl;
        }
        else if (commands == "exit"){
            exit(0);
        }
        else if (commands == "pwd"){
            std::cout << fs::current_path() << std::endl;
        }
        // I checked the official documentation and chatgpt for this....
        else if (commands == "ls") {
            for (const auto& entry : fs::directory_iterator(".")) { // here, (".") means that we are going for current directory only...
                std::cout << entry.path() << '\n';
            }
        }
        else if (commands == "tree"){
            std::system("tree");
        }

        // now...I will start implementing some required functions....
        else if (commands == "calc" || commands == "calculator"){
            calculator();
        }

        else{
            std::cout << commands << " is not available." << std::endl;
        }
    }
    return 0;
}
