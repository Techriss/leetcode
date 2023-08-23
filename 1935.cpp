#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;

// we can also use boolean array of 26, being O(1) not log 26
int canBeTypedWords(string text, string brokenLetters) {
    unordered_set<char> s(brokenLetters.begin(), brokenLetters.end());
    int c = 0;
    istringstream iss(text);
    string word;

    while (iss >> word) {
        bool ok = true;
        for (auto &c : word) {
            if (s.count(c)) { ok = false; break; }
        }

        c += ok;
    }

    return c;   
}