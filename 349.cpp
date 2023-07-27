#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    auto s2 = unordered_set(nums2.begin(), nums2.end());
    unordered_set<int> was;

    vector<int> common;
    for (auto x : nums1) {
        if (s2.find(x) != s2.end() && was.find(x) == was.end()) {
            common.push_back(x);
            was.insert(x);
        }
    }

    return common;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> common;
    unordered_map<int, int> m;
    for (auto x : nums1) m[x]++;
    for (auto x : nums2) {
        if (m[x]) {
            m[x] = 0;
            common.push_back(x);
        }
    }

    return common;
}