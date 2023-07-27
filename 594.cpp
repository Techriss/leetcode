#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

int findLHS(vector<int>& nums) {
    unordered_map<int, int> m;
    vector<int> v;
    for (auto x : nums) m[x]++;
    for (auto x : m) {
        if (m.find(x.first-1) == m.end() && m.find(x.first+1) == m.end()) continue;
        if (m.find(x.first-1) == m.end()) v.push_back(x.second + m[x.first+1]);
        else if (m.find(x.first+1) == m.end()) v.push_back(x.second + m[x.first-1]);
        else v.push_back(max(x.second + m[x.first-1], x.second + m[x.first+1]));
    }
    sort(v.begin(), v.end());

    if (!v.empty()) return v[v.size()-1];
    return 0;
}

int main() {
    vector<int> v({1,4,1,3,1,-14,1,-13});
    cout << findLHS(v) << endl;
}