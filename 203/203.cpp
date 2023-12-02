//
// Created by kenzo on 02/12/23.
//
#include <iostream>
#include "../tools.h"

int main() {
    using namespace std;
    vector<string> data = readData(203);
    uint16_t gamma = 0;

    for (int i = 0; i < data[0].size(); ++i) {
        int ones = 0;
        int zeros = 0;
        for (auto& line : data) {
            if (line[i] == '1') {
                ones++;
            }
            else {
                zeros++;
            }
        }
        if (ones > zeros) {
            uint16_t mask = 1;
            mask = mask << (data[0].size() - 1 - i);
            gamma = gamma | mask;
        }
    }

    uint16_t epsilon = ~gamma & 0b111111111111;

    cout << gamma * epsilon << endl;
}