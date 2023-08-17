#include <iostream>
#include <vector>
using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
    vector<bool> v(26, 0);
    for (auto &c : allowed) v[c-'a'] = true;
    
    int good = 0;
    for (auto &w : words) {
        bool alright = true;
        for (auto &c : w) {
            if (!v[c-'a']) { alright = false; break; }
        }

        if (alright) ++good;
    }

    return good;
}