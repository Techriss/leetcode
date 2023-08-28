#include <iostream>
#include <unordered_map>
using namespace std;

// sliding window
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> m;
    int l = 0, r = 0, maxv = 0;
    ++m[s[0]];

    while (r < s.size()) {
        if (r-l+1 > m.size()) {
            if (--m[s[l]] == 0) m.erase(s[l]);
            ++l;
        }   
        else {
            maxv = max(maxv, r-l+1);
            if (++r < s.size()) ++m[s[r]];
        }
    }

    return maxv;
}