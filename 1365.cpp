#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// map
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    unordered_map<int, int> m;
    vector<int> v = nums;
    sort(v.begin(), v.end());

    m[v[0]] = 0;
    for (int i = 1, c = 0, same = 0; i < v.size(); i++) {
        if (v[i] > v[i-1]) { c += same + 1;  same = 0; }
        else ++same;
        m[v[i]] = c;
    }

    for (auto &x : nums) {
        x = m[x];
    }

    return nums;
}



// or prefix sums
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int i, j;
    int count[101] = {0, 0, 0};
    const int len = nums.size();
    vector<int> ans(len);

    for (auto &x : nums) count[x]++;

    for (i = 1; i < 101; i++) count[i] += count[i-1];
    for (i = 0; i < len; i++) {
        if (nums[i] == 0) ans[i] = 0;
        else ans[i] = count[nums[i] - 1];  
    }

    return ans;
}


// or another way with map
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    unordered_map<int, int> map;
    vector<int> arr = nums;
    sort(arr.begin(), arr.end());

    // automatically omits duplicates (since they're already in map)
    for (int i = 0; i < arr.size(); i++) {
        if (map.find(arr[i]) == map.end()) {
            map[arr[i]] = i;
        }
    }

    for (auto &x : nums) {
        x = map[x];
    }
    return nums;
}