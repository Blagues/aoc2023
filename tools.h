//
// Created by kenzo on 01/12/23.
//

#ifndef FILE_READER_H
#define FILE_READER_H

#include <vector>
#include <string>

std::vector<std::string> readData(const int& day);
std::vector<std::vector<std::string>> splitString(const std::vector<std::string>& data, const std::string& delimiter);
std::vector<std::string> findAllRegex(const std::string& str, const std::string& regex);

#endif
