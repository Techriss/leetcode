#include <iostream>
#include <vector>
using namespace std;

bool checkAlmostEquivalent(string word1, string word2) {
    vector<int> v(26, 0);
    for (auto &c : word1) ++v[c-'a'];
    for (auto &c : word2) --v[c-'a'];

    for (int i = 0; i < 26; i++) {
        if (abs(v[i]) > 3) return false;
    }

    return true;
}