#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int mind = INT_MAX;
    for (int i = 0; i + k - 1 < nums.size(); i++) {
        mind = min(mind, nums[i+k-1]-nums[i]);
    }

    return mind;
}