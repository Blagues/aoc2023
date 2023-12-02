//
// Created by kenzo on 01/12/23.
//

#include "./tools.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

std::vector<std::string> readData(const int& day) {
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


std::vector<std::vector<std::string>> splitString(const std::vector<std::string>& data, const std::string& delimiter) {
    std::vector<std::vector<std::string>> result;

    for (const auto& line : data) {
        std::vector<std::string> temp;
        std::string str = line;
        size_t pos = 0;
        std::string token;

        while ((pos = str.find(delimiter)) != std::string::npos) {
            token = str.substr(0, pos);
            temp.push_back(token);
            str.erase(0, pos + delimiter.length());
        }

        temp.push_back(str);
        result.push_back(temp);
    }

    return result;
}

std::vector<std::string> findAllRegex(const std::string& str, const std::string& regex) {
    std::vector<std::string> result;

    std::regex reg(regex);
    for (auto it = std::sregex_iterator(str.begin(), str.end(), reg); it != std::sregex_iterator(); it++) {
        result.push_back(it->str());
    }

    return result;
}