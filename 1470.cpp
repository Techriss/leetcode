#include <iostream>
#include <vector>
using namespace std;

// O(N) space
vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> v;

    for (int i = 0; i < n; i++) {
        v.push_back(nums[i]);
        v.push_back(nums[n+i]);
    }

    return v;
}

// using the nums space itself as the numbers are limited to 1000 (we can store 2 numbers in one by leftshifting)
vector<int> shuffle(vector<int>& nums, int n) {
    for (int i = n-1; i >= 0; i--) {
        nums[i+n] <<= 10;
        nums[i+n] |= nums[i];
    }

    for (int i = 0, j = n; j < 2*n; j++, i += 2) {
        nums[i] = nums[j] & 1023;
        nums[i+1] = nums[j] >> 10;
    }

    return nums;
}