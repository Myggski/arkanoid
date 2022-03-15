#include "file_handler.h"

#include <fstream>
#include <iostream>

void FileHandler::save_to_file(std::vector<std::string> level) 
{
    std::fstream file("level.txt", std::ios::out | std::ios::trunc);

    if (!file.is_open()) {
        std::cout << "Could not open/create file for some reason. Check your read/write permissions. \n";
        return;
    }

    for (auto level_str : level) {
        file << level_str << "\n";
    }
}

std::vector<std::string> FileHandler::load_from_file()
{
    std::vector<std::string> level;
    std::fstream file("level.txt", std::ios::in | std::ios::out);
    std::string str;

    if (!file.is_open()) {
        return level;
    }

    while (std::getline(file, str))
    {
        level.push_back(str);
    }

    return level;
}

void FileHandler::clear_file() {
    std::fstream file("level.txt", std::ios::out | std::ios::trunc);
}