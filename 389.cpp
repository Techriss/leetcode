#include <iostream>
#include <unordered_map>
using namespace std;

char findTheDifference(string s, string t) {
    unordered_map<char, int> m;
    for (auto c : s) m[c]++;
    for (auto c : t) {
        if (m.find(c) == m.end() || m[c] == 0) return c;
        m[c]--;
    }

    return ' ';
}