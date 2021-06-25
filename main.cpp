#include <iostream>
#include <string>
#include "commands.h"

// Only for user input
int main() {

    std::string input;
    commands command;
    
    // Print when opening the terminal
    command.initialprint();

    // Main loop
    while(input!="exit") {
        std::cout<<"$ ";
        std::cin>>input;
        command.checkInput(input);
    }
}