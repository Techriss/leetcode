#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

// maps
vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> freq;
    map<int, vector<int>> v;

    for (auto &x : nums) ++freq[x];
    for (auto &p : freq) v[p.second].push_back(p.first);

    vector<int> res;
    for (auto &x : v) {
        sort(x.second.begin(), x.second.end(), greater<int>());
        for (auto &v : x.second) {
            for (int i = 0; i < x.first; i++) res.push_back(v);
        }
    }

    return res;
}

// or modified sort
vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> count;
    for (auto &x : nums) ++count[x];
    sort(nums.begin(), nums.end(), [&](int a, int b) {
        return count[a] == count[b] ? a > b : count[a] < count[b];
    });

    return nums;
}