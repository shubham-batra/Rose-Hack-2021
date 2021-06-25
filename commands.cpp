#include "commands.h"
#include <iostream>
#include <string>
#include <fstream> // Read and write to files
#include <sys/stat.h> // To check if file exists

void commands::initialprint() {
    std::cout<<"Welcome to the music database!\n";
    std::cout<<"Type help to get a list of commands. Type exit to leave program.\n";
}
void commands::checkInput(std::string input ) {
    if(input=="help") {
        printHelp();
    }
    else if(input=="exit") {
        // Leave empty
    }
    else if(input=="newdb") {
        createDatabase();
    }
    else if(input=="rmdb") {
        removeDatabase();
    }
    else if(input=="newentry") {
        enterEntry();
    }
    else {
        std::cout<<"That is not a valid command, try again\n";
    }
}
void commands::printHelp() {
    std::cout<<"Current Commands\n\n";
    std::cout<<"help: Prints out a list of visible commands\n";
    std::cout<<"newdb: Creates new database\n";
    std::cout<<"rmdb: Deletes current database\n";
    std::cout<<"newentry: Creates a new entry in the database\n";
}

void commands::createDatabase() {
    bool check = fileExists("database.txt");
    if (check == false) {
        std::ofstream MyFile("database.txt");
        MyFile.close();
    }
    else {
        std::cout<<"File already exists.\n";
    }
}

void commands::removeDatabase() {
    
    std::remove("database.txt"); // delete file
}

bool commands::fileExists(const std::string& filename) {
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1) {
        return true;
    }
    return false;
}

void commands::enterEntry() {
    std::string album;
    std::string artist;
    int rating;

    std::cout<<"Enter the album name\n";
    std::cin>>album;
    std::cout<<"Enter the artist name\n";
    std::cin>>artist;
    std::cout<<"Enter your personal rating\n";
    std::cin>>rating;

    std::ofstream MyFile;
    MyFile.open("database.txt", std::fstream::app);
    MyFile << album << " " << artist << " " << rating << "\n";
    MyFile.close();
}


