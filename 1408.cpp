#include <iostream>
#include <vector>
using namespace std;

// brute (actually beats 100%)
vector<string> stringMatching(vector<string>& words) {
    vector<string> v;
    for (auto &w : words) {
        for (auto &x : words) {
            if (w != x && x.find(w) != string::npos) { v.push_back(w); break; }
        }
    }

    return v;
}