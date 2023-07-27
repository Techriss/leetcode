#include <iostream>
#include <unordered_map>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> m;
    int res = 0;
    for (auto c : s) {
        if (m.find(c) == m.end()) m[c] = 1;
        else {
            m.erase(c);
            res += 2;
        }
    }

    if (s.size()-res >= 1) res++;
    return res;
}