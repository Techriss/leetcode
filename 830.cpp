#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> v;
    char prev = ' ';
    int count = 0, l, r;

    s += ' ';

    for (int i = 0; i < s.size(); i++) {
        if (prev == s[i]) { r++; count++; }
        else {
            if (count >= 3) v.push_back({l, r});
            l = r = i;
            count = 1;
            prev = s[i];
        }
    }

    return v;
}