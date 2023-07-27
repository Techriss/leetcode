#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// we could use a map (trusted) and a set (trusting)
// but we can also simply subtract from the trusted if he trusts someone (making its value not n-1)
// thus using only a map
// => can also use an array instead of map
int findJudge(int n, vector<vector<int>>& trust) {
    unordered_map<int, int> trusted;

    for (auto &p : trust) { trusted[p[1]]++; trusted[p[0]]--; }

    int maxv = 0, maxt = 1;
    for (auto &t : trusted) {
        if (t.second > maxv) {
            maxv = t.second;
            maxt = t.first;
        }
    }

    return (maxv == (n-1)) ? maxt : -1;
}