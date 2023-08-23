#include <iostream>
using namespace std;

// erase every 1 of three consecutives (too slow) [TLE]
string makeFancyString(string s) {
    for (int i = 2; i < s.size(); i++) {
        if (s[i-2] == s[i-1] && s[i-1] == s[i]) { s.erase(s.begin() + i-2);}
    }

    return s;
}

// add or not depending on the current count of consecutives
string makeFancyString(string s) {
    string res = "";
    res += s[0];
    int c = 1;

    for (int i = 1; i < s.size(); i++) {
        c = s[i] == s[i-1] ? c+1 : 1;
        if (c < 3) res.push_back(s[i]);
    }

    return res;
}


// or two pointers - fast (scan every char) and slow (for inserting)
string makeFancyString(string s) {
    int j = 2;
    for (int i = 2; i < s.size(); ++i)
        if (s[i] != s[j - 1] || s[i] != s[j - 2])
            s[j++] = s[i];

    s.resize(min(j, (int)s.size()));
    return s;
}


// or combine both
string makeFancyString(string s) {
    int cnt = 0, i = 0;
    char prev = s[0];
    
    for (auto &c : s) {
        cnt = prev == cnt ? cnt+1 : 1;
        prev = c;
        if (cnt < 3) s[i++] = c;
    }
    
    s.erase(i);
    return s;
}