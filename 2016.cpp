#include <iostream>
#include <vector>
using namespace std;

// using map
int maximumDifference(vector<int>& nums) {
    const int n = nums.size();
    int diff = 0;
    vector<int> rmax(n);
    rmax[n-1] = nums[n-1];
    for (int i = n-2; i >= 0; i--) rmax[i] = max(rmax[i+1], nums[i]);
    for (int i = 0; i < n-1; i++)
        diff = max(diff, rmax[i+1]-nums[i]);

    return diff == 0 ? -1 : diff;
}


// constant space [121. best time to buy and sell stock]
int maximumDifference(vector<int>& nums) {
    int maxv = -1;
    const int n = nums.size();

    for (int l = 0, r = 1; r < n; r++) {
        if (nums[l] < nums[r]) maxv = max(maxv, nums[r]-nums[l]);
        else l = r;
    }

    return maxv;
}

// another version
// mn is our l, i is our r
int maximumDifference(vector<int>& nums) {
    int mn = nums[0], res = -1;
    for (int i = 1; i < nums.size(); ++i) {
        res = max(res, nums[i] - mn);
        mn = min(mn, nums[i]);
    }
    return res == 0 ? -1 : res;
}