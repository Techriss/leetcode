#include <iostream>
#include <vector>
using namespace std;

bool palindrome(string &s) {
    for (int l = 0, r = s.size()-1; l < r; l++, r--)
        if (s[l] != s[r]) return false;

    return true;
}

string firstPalindrome(vector<string>& words) {
    for (auto &w : words)
        if (palindrome(w)) return w;

    return "";
}



// or reverse
string firstPalindrome(vector<string>& words) {
    for (auto &w : words)
        if (w == string(rbegin(w), rend(w)))
            return w;
    return "";
}