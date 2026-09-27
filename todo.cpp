#include <iostream>
#include <string>
#include <filesystem>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <random>

int main() {
    std::string commands;
    std::vector<std::string> todo;
    int x = 1;

    while (true) {
        std::cout << "gfm> ";
        std::getline(std::cin, commands);

        if (commands.empty()) {
            continue;
        }

        if (commands[0] == 't' &&
            commands[1] == 'a' &&
            commands[2] == 's' &&
            commands[3] == 'k' &&
            commands[4] == ' ' &&
            commands[5] == 'a' &&
            commands[6] == 'd' &&
            commands[7] == 'd') {

            std::string task;

            for (int i = 9; i < commands.length(); i++) {
                task.push_back(commands[i]);
            }

            todo.push_back(std::to_string(x) + ". " + task);
            x++;
        }

            else if (commands[0] == 't' &&
                    commands[1] == 'a' &&
                    commands[2] == 's' &&
                    commands[3] == 'k' &&
                    commands[4] == ' ' &&
                    commands[5] == 'r' &&
                    commands[6] == 'm' &&
                    commands[7] == ' ') {

                int taskNumber = std::stoi(commands.substr(8));

                if (taskNumber >= 1 && taskNumber <= todo.size()) {
                    todo.erase(todo.begin() + taskNumber - 1);
                }
            }
        
            else if (commands[0] == 't' &&
            commands[1] == 'a' &&
            commands[2] == 's' &&
            commands[3] == 'k' ){
                for (const std::string& item : todo){
                    std::cout << item << '\n';
                }
            }
    }
}