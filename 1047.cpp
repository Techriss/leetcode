#include <iostream>
#include <algorithm>
using namespace std;


// stack-like
string removeDuplicates(string s) {
    string res = "";

    for (auto &c : s) {
        if (!res.empty() && res[res.size()-1] == c) res.pop_back();
        else res += c;
    }

    return res;
}

// two pointers
string removeDuplicates(string s) {
    int i = 0, n = s.length();
    for (int j = 0; j < n; ++j, ++i) {
        s[i] = s[j];
        if (i > 0 && s[i - 1] == s[i]) // count = 2
            i -= 2;
    }
    return s.substr(0, i);
}