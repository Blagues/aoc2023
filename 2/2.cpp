//
// Created by kenzo on 01/12/23.
//

#include "../tools.h"
#include "iostream"
#include "iterator"

int main() {
    using namespace std;
    vector<string> data = readData(2);

    int possibleTotal = 0;

    for (auto& line : data) {
        int maxBlue = INT32_MIN;
        int maxGreen = INT32_MIN;
        int maxRed = INT32_MIN;

        vector<string> numbers = findAllRegex(line, R"(\d+)");
        vector<string> colors = findAllRegex(line, R"([a-z]+)");

        for (int i = 1; i < numbers.size(); i++) {
            int number = stoi(numbers[i]);
            string color = colors[i];

            if (color == "blue") {
                if (number > maxBlue) {
                    maxBlue = number;
                }
            } else if (color == "green") {
                if (number > maxGreen) {
                    maxGreen = number;
                }
            } else if (color == "red") {
                if (number > maxRed) {
                    maxRed = number;
                }
            }
        }

        possibleTotal += maxBlue * maxGreen * maxRed;

    }
    cout << possibleTotal << endl;
}
