#include <iostream>
#include <unordered_map>
using namespace std;


bool isIsomorphic(string s, string t) {
    unordered_map<char, char> m1;
    unordered_map<char, char> m2;

    for (int i = 0; i < s.size(); i++) {
        if (!m1.count(s[i])) m1[s[i]] = t[i];
        if (!m2.count(t[i])) m2[t[i]] = s[i];
        else if (m1[s[i]] != t[i] || m2[t[i]] != s[i]) return false;
    }

    return true;
}