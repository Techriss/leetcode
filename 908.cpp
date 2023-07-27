#include <iostream>
#include <vector>
using namespace std;

// minmax, then converge, then minmax again
int smallestRangeI(vector<int>& nums, int k) {
    int minv = INT_MAX, maxv = INT_MIN;
    for (auto &x : nums) {
        minv = min(minv, x);
        maxv = max(maxv, x);
    }
    int avg = (minv+maxv)/2;

    for (auto &x : nums) {
        if (x > avg) x = x-min(x-avg, k);
        else x = x+min(avg-x, k);
    }

    minv = INT_MAX, maxv = INT_MIN;
    for (auto &x : nums) {
        minv = min(minv, x);
        maxv = max(maxv, x);
    }
    return maxv-minv;
}

// quicker - you dont have to simulate anything, just calculate it
// the most you can do is to reduce range by 2K
int smallestRangeI(vector<int> A, int K) {
    int mx = A[0], mn = A[0];
    for (int a : A) mx = max(mx, a), mn = min(mn, a);
    return max(0, mx - mn - 2 * K);   // max as you cannot cut more than 2k and less than 0 is not needed
}