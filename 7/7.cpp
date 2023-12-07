#include <iostream>
#include "tuple"
#include "vector"
#include "string"
#include "../tools.h"
#include "algorithm"

using namespace std;

vector<int> getPairs(string &s) {
    vector<char> found;
    vector<int> occurances;
    int js = 0;
    for (auto &c: s) {
        bool a = false;
        for (auto &f: found) {
            if (c == f) { a = true; }
        }
        if (!a) {
            if (c == 'J') {
                js++;
                occurances.push_back(0);
                continue;
            }
            occurances.push_back(count(s.begin(), s.end(), c));
            found.push_back(c);
        }

    }
    sort(occurances.begin(), occurances.end(), greater<>());

    occurances[0] += js;

    return occurances;
}

class Hand {
public:
    string hand;
    vector<int> occs;
    int bid{};
    int rank{};

    Hand(string hand, vector<int> occs, int bid, int rank) {
        this->hand = hand;
        this->occs = occs;
        this->bid = bid;
        this->rank = rank;
    }

};

int cardToInt(const char &card) {
    switch (card) {
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'T':
            return 10;
        case 'J':
            return 1;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        case 'A':
            return 14;
        default:
            return -1;
    }
}

bool isLower(Hand &a, Hand &b) {
    // 5 of a kind
    if (a.occs[0] == 5 && b.occs[0] != 5) return false;
    if (b.occs[0] == 5 && a.occs[0] != 5) return true;
    // 4 of a kind
    if (a.occs[0] == 4 && b.occs[0] != 4) return false;
    if (b.occs[0] == 4 && a.occs[0] != 4) return true;
    // FH
    if ((a.occs[0] == 3 && a.occs[1] == 2) && (b.occs[0] != 3 || b.occs[1] != 2)) return false;
    if ((b.occs[0] == 3 && b.occs[1] == 2) && (a.occs[0] != 3 || a.occs[1] != 2)) return true;
    // 3 of a kind
    if (a.occs[0] == 3 && b.occs[0] != 3) return false;
    if (b.occs[0] == 3 && a.occs[0] != 3) return true;
    // 2 pair
    if ((a.occs[0] == 2 && a.occs[1] == 2) && (b.occs[0] != 2 || b.occs[1] != 2)) return false;
    if ((b.occs[0] == 2 && b.occs[1] == 2) && (a.occs[0] != 2 || a.occs[1] != 2)) return true;
    // one pair
    if (a.occs[0] == 2 && b.occs[0] != 2) return false;
    if (b.occs[0] == 2 && a.occs[0] != 2) return true;

    // check High card
    for (int i = 0; i < a.hand.size(); ++i) {
        int valA = cardToInt(a.hand[i]);
        int valB = cardToInt(b.hand[i]);

        if (valA > valB) return false;
        if (valA == valB) continue;
        if (valA < valB) return true;
    }

    return false;
}

int main() {
    vector<string> lines = readLines(7);

    vector<Hand> hands; // hand, occ, bid, rank

    for (string &line: lines) {
        vector<string> split = splitString(line, " ");
        Hand h = Hand(split[0], getPairs(split[0]), stoi(split[1]), 0);
        hands.push_back(h);
    }

    sort(hands.begin(), hands.end(), isLower);

    int total = 0;

    for (int i = 0; i < hands.size(); ++i) {
        cout << hands[i].hand << " " << getPairs(hands[i].hand)[0] << " " << getPairs(hands[i].hand)[1] << endl;
        total += (i + 1) * hands[i].bid;
    }

    cout << total;

}
