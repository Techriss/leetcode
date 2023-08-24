#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// bool[3]
vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    vector<vector<bool>> m(101, vector<bool>(3, false));
    vector<int> v;

    for (auto &x : nums1) m[x][0] = true;
    for (auto &x : nums2) m[x][1] = true;
    for (auto &x : nums3) m[x][2] = true;
    for (int i = 1; i <= 100; i++)
        if (m[i][0] + m[i][1] + m[i][2] >= 2) v.push_back(i);

    return v;
}

// masking
vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    vector<int> f(110, 0);
    for (int &n : nums1) f[n] |= 1<<0;
    for (int &n : nums2) f[n] |= 1<<1;
    for (int &n : nums3) f[n] |= 1<<2;
    
    vector<int> ret;
    for (int i = 1; i <= 100; i++) if (f[i] == 3 || f[i] >= 5) ret.push_back(i);
    return ret;
}