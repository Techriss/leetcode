#include <iostream>
using namespace std;

// manual
string truncateSentence(string s, int k) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' && --k == 0) return s.substr(0, i);
    }

    return s;
}