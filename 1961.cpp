#include <iostream>
#include <vector>
using namespace std;

// in place
bool isPrefixString(string s, vector<string>& words) {
    int i, j, w;
    for (i = 0, j = 0, w = 0; i < s.size() && w < words.size(); i++, j++) {
        if (s[i] != words[w][j]) return false;
        if (j == words[w].size()-1) j = -1, ++w;
    }

    return i == s.size() && j == 0;
}


// or appending
bool isPrefixString(string s, vector<string>& words) {
    string check = "";
    
    for (auto &w : words) {
        check += w;
        
        if (check == s) return true;
        if (check.length() >= s.length()) return false;
    }
    
    return false;
}