#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// use map and own sorted
bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> m;
    for (int i = 0; i < order.size(); i++) m[order[i]] = i;

    for (int i = 1; i < words.size(); i++) {
        int j; bool same = true;
        for (j = 0; j < words[i-1].size() && j < words[i].size(); j++) {
            if (m[words[i-1][j]] > m[words[i][j]]) return false;
            else if (m[words[i-1][j]] < m[words[i][j]]) { same = false; break; }
        }

        if (words[i-1].size() == words[i].size()) continue;
        else if (j == words[i].size() && same) return false;
    }

    return true;
}

// use vector and built-in sorted
bool isAlienSorted(vector<string> words, string order) {
    int mapping[26];
    for (int i = 0; i < 26; i++)
        mapping[order[i] - 'a'] = i;      // asign each char an index from order
    for (string &w : words)
        for (char &c : w)
            c = mapping[c - 'a'];         // swap char with its index
    return is_sorted(words.begin(), words.end());
}