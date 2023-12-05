//
// Created by kenzo on 05/12/23.
//

#include "vector"
#include "string"
#include "../tools.h"
#include "cmath"
#include "iostream"
#include "tuple"


int main() {
    using namespace std;
    vector<string> data = readData(5);
    vector<std::tuple<uint64_t, uint64_t, bool>> seeds;


    vector<string> seedRanges = findAllRegex(data[0], R"(\d+)");
    for (int i = 0; i < seedRanges.size(); i+=2 ) {
        seeds.emplace_back(stol(seedRanges[i]), stol(seedRanges[i]) + stol(seedRanges[i + 1]), false);
    }

    for (int i = 3; i < data.size(); i++) {
        string line = data[i];
        vector<string> numbersInLine = findAllRegex(line, R"(\d+)");


        if (!numbersInLine.empty()) {
            uint64_t l = stol(numbersInLine[2]);
            uint64_t s = stol(numbersInLine[1]);
            uint64_t e = l + s;
            uint64_t d = stol(numbersInLine[0]);
            uint64_t diff = d - s;

            vector<std::tuple<uint64_t, uint64_t, bool>> newRanges;
            for (auto seed : seeds) {
                if (get<2>(seed)) {
                    newRanges.emplace_back(seed);
                    continue;
                }; // skip already mutated values

                uint64_t rangeStart = get<0>(seed);
                uint64_t rangeEnd = get<1>(seed);

                if ((rangeStart >= s) && (rangeStart < e) || ((rangeEnd > s) && (rangeEnd <= e))) {

                    uint64_t containedRangeStart = max(rangeStart, s);
                    uint64_t containedRangeEnd = min(rangeEnd, e);

                    newRanges.emplace_back(containedRangeStart + diff, containedRangeEnd + diff, true);

                    if (rangeStart < s) {
                        newRanges.emplace_back(rangeStart, s , false);
                    }
                    if (rangeEnd > e) {
                        newRanges.emplace_back(e, rangeEnd, false);
                    }
                } else {
                    newRanges.emplace_back(seed);                }
                }
            seeds = newRanges;
        } else {
            cout << "SEEDS: " << seeds.size() << endl;
            for (auto& t : seeds) {
                get<2>(t) = false;
            }
        }
    }

    uint64_t min = INFINITY;

    for (auto seed : seeds) {
        cout << get<0>(seed) << " " << get<1>(seed) << endl;
        if (get<0>(seed) < min) min = get<0>(seed);
    }

    cout << fixed <<  min;

    return 0;
}
