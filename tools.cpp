//
// Created by kenzo on 01/12/23.
//

#include "./tools.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

std::vector<std::string> readLines(const int& day) {
    std::string path = "../data/" + std::to_string(day) + ".txt";
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


std::vector<std::string >splitString(std::string& data, const std::string& delimiter) {
    std::vector<std::string> result;

    while (data.find(delimiter) != std::string::npos) {
        result.push_back(data.substr(0, data.find(delimiter)));
        data = data.substr(data.find(delimiter) + 1);
    }

    result.push_back(data);

    return result;
}

std::vector<std::string> getAllRegex(const std::string& str, const std::string& regex) {
    std::vector<std::string> result;

    std::regex reg(regex);
    for (auto it = std::sregex_iterator(str.begin(), str.end(), reg); it != std::sregex_iterator(); it++) {
        result.push_back(it->str());
    }

    return result;
}