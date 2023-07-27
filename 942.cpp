#include <iostream>
#include <vector>
using namespace std;

vector<int> diStringMatch(string s) {
    vector<int> v;
    int maxv = s.size();
    int minv = 0;
    for (auto c : s) {
        if (c == 'I') v.push_back(minv++);
        else v.push_back(maxv--);
    }

    if (s[s.size()-1] == 'I') v.push_back(maxv);
    else v.push_back(minv);

    return v;
}