#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// two maps
int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> m1, m2;
    for (auto &s : words1) ++m1[s];
    for (auto &s : words2) ++m2[s];

    int res = 0;
    for (auto &p : m1)
        if (p.second == 1 && m2[p.first] == 1) ++res;
    
    return res;
}

// or one map
int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> m;
    for (auto &s : words1) ++m[s];
    for (auto &s : words2)
        if (m[s] < 2) --m[s];

    int res = 0;
    for (auto &p : m)
        if (p.second == 0) ++res;
    
    return res;
}