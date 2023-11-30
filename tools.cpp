//
// Created by kenzo on 01/12/23.
//

#include "tools.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> readData(const int& day) {
    std::string path = "data/" + std::to_string(day) + ".txt";
    std::vector<std::string> lines;
    std::ifstream file(path);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " + path << std::endl;
    }

    return lines;
}