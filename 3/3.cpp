#include <iostream>
#include <vector>
#include <string>
#include "../tools.h"
#include "algorithm"

using namespace std;

// Function to check if a character is a symbol
bool isSymbol(char c) {
    return !isdigit(c) && c != '.';
}

// Function to check if a number is adjacent to a symbol
bool isNumberAdjacentToSymbol(const vector<string>& schematic, int i, int j) {
    int rows = schematic.size();
    int cols = schematic[0].size();

    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            int ni = i + di;
            int nj = j + dj;

            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && isSymbol(schematic[ni][nj])) {
                return true;
            }
        }
    }
    return false;
}

// Function to calculate the sum of gear ratios
int sumOfGearRatios(const vector<string>& schematic) {
    int sum = 0;
    int rows = schematic.size();
    int cols = schematic[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (schematic[i][j] == '*') {
                vector<int> adjacentNumbers;

                // Check non-diagonal adjacent positions
                for (int di = -1; di <= 1; di += 1) {
                    for (int dj = -1; dj <= 1; dj += 1) {
                        int ni = i + di;
                        int nj = j + dj;

                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && isdigit(schematic[ni][nj])) {
                            int a = nj;
                            int b = nj;
                            while (a > 0 && isdigit(schematic[ni][a - 1])) a--;
                            while (b < cols && isdigit(schematic[ni][b])) b++;
                            string number = schematic[ni].substr(a, b - a);

                            adjacentNumbers.push_back(stoi(number));
                        }
                    }
                }

                // Calculate gear ratio if there are exactly two adjacent numbers
                if (adjacentNumbers.size() >= 2) {
                    vector<int> uniqueNumbers;
                    for (int number : adjacentNumbers) {
                        if (find(uniqueNumbers.begin(), uniqueNumbers.end(), number) == uniqueNumbers.end()) {
                            uniqueNumbers.push_back(number);
                        }
                    }
                    if (uniqueNumbers.size() == 2) {
                        sum += uniqueNumbers[0] * uniqueNumbers[1];
                    }
                }
            }
        }
    }

    return sum;
}

int main() {
    vector<string> schematic = readData(3);

    int totalGearRatioSum = sumOfGearRatios(schematic);
    cout << "Sum of all gear ratios: " << totalGearRatioSum << endl;

    return 0;
}
