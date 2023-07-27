#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

string destCity(vector<vector<string>>& paths) {
    unordered_set<string> s1;
    for (auto &x : paths) s1.insert(x[0]);
    for (auto &x : paths) if (!s1.count(x[1])) return x[1];

    return "";
}

