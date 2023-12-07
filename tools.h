//
// Created by kenzo on 01/12/23.
//

#ifndef FILE_READER_H
#define FILE_READER_H

#include <vector>
#include <string>

std::vector<std::string> readLines(const int& day);
std::vector<std::string> splitString(std::string& data, const std::string& delimiter);
std::vector<std::string> getAllRegex(const std::string& str, const std::string& regex);

#endif
