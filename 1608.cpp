#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute
int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= nums.size(); i++) {
        int cnt = 0;
        for (int j = nums.size()-1; j >= 0; j--) {
            if (nums[j] >= i) cnt++;
        }

        if (cnt == i) return i;
        if (cnt < i) return -1;
    }

    return -1;
}

// binary search
int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = 1; i <= nums.size(); i++) {
        auto lb = lower_bound(nums.begin(), nums.end(), i);
        if (distance(lb, nums.end()) == i) return i;
    }

    return -1;
}

// binary search binary search
int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int l = 1, r = nums.size();

    while (l <= r) {
        int mid = (l+r)/2;

        auto lb = lower_bound(nums.begin(), nums.end(), mid);
        int d = distance(lb, nums.end());

        if (d == mid) return mid;
        else if (d > mid) l = mid+1;
        else r = mid-1;
    }

    return -1;
}

int specialArray(vector<int>& nums) {
    int count[102] = { 0 }, N = nums.size();

    // count occurs
    for (int &n : nums) count[min(n, N)]++;

    // accumulate how many are greater or equal 
    for (int &i = N; i >= 0; i--) {
        count[i] += count[i + 1];
        if (count[i] == i) return i;
    }

    return -1;
}