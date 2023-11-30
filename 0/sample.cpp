//
// Created by kenzo on 01/12/23.
//

#include "../tools.h"

int main() {
    std::vector<std::string> data = readData(0);

    int n = 0;
    int last = INT32_MAX;

    for (int i = 0; i < data.size() - 2; i++) {
        int current = std::stoi(data[i]) + std::stoi(data[i + 1]) + std::stoi(data[i + 2]);
        if (current > last) {
            n++;
        }
        last = current;
    }

    printf("%d\n", n);
}
