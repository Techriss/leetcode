#include <iostream>
#include <vector>
using namespace std;

bool areOccurrencesEqual(string s) {
    vector<int> v(26, 0);
    for (auto &c : s) ++v[c-'a'];

    int count = v[s[0]-'a'];
    for (auto &c : v) {
        if (c && c != count) return false;
    }

    return true;
}