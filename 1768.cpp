#include <iostream>
using namespace std;

string mergeAlternately(string word1, string word2) {
    const int n = word1.size(), m = word2.size();
    string s = "";
    int i;

    for (i = 0; i < n && i < m; i++) {
        s.push_back(word1[i]);
        s.push_back(word2[i]);
    }

    if (n == m) return s;
    if (n > m) s += word1.substr(i);
    else s += word2.substr(i);

    return s;
}