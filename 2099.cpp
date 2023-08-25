#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

// hyp: k largest elements
// res: thats true, but you have to preserve the initial order of them
vector<int> maxSubsequence(vector<int>& nums, int k) {
    auto snums = nums;
    sort(snums.begin(), snums.end());

    const int n = nums.size();
    vector<int> v;

    // count all of k highest elements
    unordered_map<int, int> m;
    for (int i = n-k; i < n; i++) ++m[snums[i]];

    // if one of k highest found, push it back
    for (auto &x : nums)
        if (m[x]-- > 0) v.push_back(x);

    return v;
}


// another solution (may be faster a bit)
// maintain a vector of k elements
// for every x from nums, swap the current min of k elements with it if its greater
vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> v(k);

    for (int i = 0; i < k; i++) v[i] = nums[i];

    for (int i = k; i < nums.size(); i++) {
        auto mini = min_element(v.begin(), v.end());

        if (nums[i] > *mini) {
            v.erase(mini);
            v.push_back(nums[i]);
        }
    }

    return v;
}