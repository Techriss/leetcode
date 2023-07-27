#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> common;
    unordered_map<int, int> m;

    for (auto x : nums1) m[x]++;
    for (auto x : nums2) {
        if (m[x]) {
            common.push_back(x);
            m[x]--;
        }
    }

    return common;
}