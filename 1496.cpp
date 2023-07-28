#include <iostream>
#include <unordered_set>
using namespace std;

// brute1
struct hashFunction {
    size_t operator()(const pair<int , int> &x) const {
        return x.first ^ x.second;
    }
};

bool isPathCrossing(string path) {
    unordered_set<pair<int, int>, hashFunction> s;
    s.insert({0, 0});
    int x = 0, y = 0;
    for (auto &c : path) {
        if (c == 'N') y++;
        else if (c == 'S') y--;
        else if (c == 'E') x++;
        else x--;

        if (s.count({x, y})) return false;
        s.insert({x, y});
    }

    return true;
}