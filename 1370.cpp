#include <iostream>
#include <vector>
using namespace std;

// count chars, alternate between pushing char by char from left and from right
string sortString(string s) {
    int n = s.size();
    vector<int> m(26);
    for (auto &c : s) m[c-'a']++;
    string res = "";
    bool way = true;

    while (n > 0) {
        if (way) for (int i = 0; i < m.size() && n > 0; i++) {
            if (m[i] == 0) continue;
            res += i + 'a';
            n--;
            m[i]--;
        }
        else for (int i = m.size()-1; i >= 0 && n > 0; i--) {
            if (m[i] == 0) continue;
            res += i + 'a';
            n--;
            m[i]--;
        }
        way ^= 1;
    } 

    return res;
}