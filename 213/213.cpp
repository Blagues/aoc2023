//
// Created by kenzo on 01/12/23.
//

# include "../tools.h"
# include "tuple"
# include "iostream"

int main() {
    using namespace std;
    vector<string> data = readData(213);
    vector<tuple<int, int>> locations;
    vector<vector<int>> map;
    vector<tuple<string, int>> folds;

    for (auto &line: data) {
        vector<string> numbers = findAllRegex(line, R"(\d+)");
        vector<string> strings = findAllRegex(line, R"([x|y])");

        if (numbers.size() == 1) {
            folds.emplace_back(strings[0], stoi(numbers[0]));
        }
    }

    int width = 0;
    int height = 0;

    for (auto &line: data) {
        vector<string> numbers = findAllRegex(line, R"(\d+)");

        if (numbers.size() == 1) {
            break;

        } else if (numbers.size() == 2) {
            int x = stoi(numbers[0]);
            int y = stoi(numbers[1]);
            if (x > width) {
                width = x;
            }
            if (y > height) {
                height = y;
            }
            locations.emplace_back(x, y);
        }
    }

    map.resize(height + 1, vector<int>(width + 1, 0));

    for (auto &location: locations) {
        int x = get<0>(location);
        int y = get<1>(location);
        map[y][x] = 1;
    }

    for (auto &fold: folds) {
        int foldPos1 = get<1>(fold);
        string side = get<0>(fold);

        if (side == "x") {
            int range = min(foldPos1, width - foldPos1);
            for (auto &y: map) {
                for (int xd = 0; xd < range; xd++) {
                    y[foldPos1 - xd - 1] += y[foldPos1 + xd + 1];
                }
            }

            for (auto &y: map) {
                y.erase(y.begin() + foldPos1, y.end());
            }
        }

        if (side == "y") {
            int range = min(foldPos1, height - foldPos1);
            for (int yd = 0; yd < range; yd++) {
                for (int x = 0; x < width + 1; x++) {
                    map[foldPos1 - yd - 1][x] += map[foldPos1 + yd + 1][x];
                }
            }

            map.erase(map.begin() + foldPos1, map.end());
            cout << range << endl;
        }

        for (auto &line: map) {
            for (auto &value: line) {
                if (value >= 1) {
                    cout << "#";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
    }


    int count = 0;
    for (auto &line: map) {
        for (auto &value: line) {
            if (value >= 1) {
                count++;
            }
        }
    }
    cout << count << endl;

}
