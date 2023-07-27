#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// sort in map, descending by negating the key
vector<string> findRelativeRanks(vector<int>& score) {
    vector<string> v(score.size());
    map<int, int> m;
    for (int i = 0; i < score.size(); i++) m[-score[i]] = i;

    int c = 1;
    for (auto x : m) {
        if (c == 1) v[x.second] = "Gold Medal";
        else if (c == 2) v[x.second] = "Silver Medal";
        else if (c == 3) v[x.second] = "Bronze Medal";
        else v[x.second] = to_string(c);
        c++;
    }

    return v;
}