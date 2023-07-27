#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// maps
int countCharacters(vector<string>& words, string chars) {
    int res = 0;
    unordered_map<char, int> m;
    for (auto &c : chars) m[c]++;

    for (auto &w : words) {
        bool skip = false;
        unordered_map<char, int> lm;
        for (auto &c : w) {
            if (++lm[c] > m[c]) { skip = true; break; }
        }

        if (!skip) res += w.size();
    }

    return res;
}


// or arrays
int countCharacters(vector<string>& words, string chars) {
    int res = 0;
    vector<int> m(26, 0);
    for (auto &c : chars) m[c-'a']++;

    for (auto &w : words) {
        bool skip = false;
        vector<int> lm(26, 0);
        for (auto &c : w) {
            if (++lm[c-'a'] > m[c-'a']) { skip = true; break; }
        }

        if (!skip) res += w.size();
    }

    return res;
}