//
// Created by kenzo on 07/12/23.
//

#include <iostream>
#include "vector"
#include "string"
#include "../tools.h"

int main() {
    using namespace std;
    vector<string> lines = readLines(6);

    vector<vector<string>> numbers;

    for (auto& line : lines) {

        string oneNumber;
        for (string& number : getAllRegex(line, R"(\d+)")) {
            oneNumber += number;
        }
        numbers.push_back(vector<string>{oneNumber});
    }

    uint64_t total = 1;

    for (uint64_t gameIdx = 0; gameIdx < numbers[0].size(); ++gameIdx) {
        uint64_t wins = 0;
        uint64_t maxTime = stol(numbers[0][gameIdx]);
        for (uint64_t time = 0; time < maxTime; ++time) {
            if ((time * (maxTime - time)) > stol(numbers[1][gameIdx])) wins++;
        }
        total *= wins;
    }


    cout << total;
}