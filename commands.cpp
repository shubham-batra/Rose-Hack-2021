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
    else if(input=="printdb") {
        printDatabase();
    }
    else if(input=="delentry") {
        //deleteEntry();
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
    std::cout<<"printdb: Prints out content of entire database\n";
    std::cout<<"delentry: Deletes an entry from the database (not implemented)\n";
    std::cout<<"yrprint: Print out all entries from a specific year (not implmented)\n";
    std::cout<<"scoreoptn: Print out all entries with a specific score only (not implemented)\n";
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

void commands::printDatabase() {
    std::ifstream MyFile("database.txt");
    int counter = 1;
    std::string input;

    /*if (MyFile.is_open()) { // Old implementation
        std::cout << counter << MyFile.rdbuf();
        counter++;
    }*/

    std::cout<<"(Artist, Album, Score)\n";

    while(getline(MyFile, input) ) { // To get you all the lines.
      std::cout << counter << ". " << input << '\n' ;
      counter++;
    }
}

/*void commands::deleteEntry() {
    std::string input;
    std::cout<<"Enter the number of the line that contains the entry you would like to delete\n";
    std::cin>>input;

    std::string deleteline;
    std::string line;

    std::ifstream MyFile;
    MyFile.open("database.txt");
    std::ofstream temp;
    temp.open("temp.txt");
    std::cout << "Input index to remove [0 based index]: "; //input line to remove

    while (getline(MyFile, line))
    {
        line.replace(line.find(), deleteline.length(), "");
        temp << line << std::endl;
    }

    temp.close();
    MyFile.close();
    remove("database.txt");
    rename("temp.txt", "database.txt");
} */
