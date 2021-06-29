#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sys/stat.h>

class commands {
public:
    void initialprint(); // Instruction that prints initially everytime
    void checkInput(std::string input); // Run corresponding operation depending on input
    void printHelp(); // Lists all commands user can do
    void createDatabase(); // Creates a new text file
    void removeDatabase(); // Deletes the text file database (Should give user warning)
    bool fileExists(const std::string& filename); // Check if file exists before deleting
    void enterEntry(); // Enter an entry into a database
    void printDatabase(); // Prints out contents of text file
    //void deleteEntry(); // Delete entry from text file
};