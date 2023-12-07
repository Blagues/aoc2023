//
// Created by kenzo on 05/12/23.
//
#include "vector"
#include "string"
#include "../tools.h"
#include "cmath"
#include "iostream"


int main() {
    using namespace std;
    vector<string> lines = readLines(4);

    vector<int> copies;

    for (int i = 0; i < lines.size(); ++i) {
        copies.push_back(1);
    }

    int totalCards = (int) lines.size();

    for (int lineNr = 0; lineNr < lines.size(); lineNr++) {
        string line = lines[lineNr];

        vector<string> numbers = getAllRegex(line, R"(\d+)");
        vector<int> winningNumbers;
        vector<int> ticketNumbers;

        for (int i = 1; i < numbers.size(); ++i) {
            if (i > 10) {
                ticketNumbers.push_back(stoi(numbers[i]));
            }
            else {
                winningNumbers.push_back(stoi(numbers[i]));
            }
        }

        int nWinning = 0;
        for (auto& ticketNr : ticketNumbers) {
            for (auto& winningNr : winningNumbers) {
                if (ticketNr == winningNr) nWinning++;
            }
        }


        int win = nWinning;

        for (int j = lineNr + 1; j < lineNr + 1 + win; j++) {
            copies[j] += copies[lineNr];
        }

        totalCards += win * copies[lineNr];
    }

    cout << totalCards;

    return 0;
}