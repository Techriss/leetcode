#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int findMiddleIndex(vector<int>& nums) {
    int l = 0, r = accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < nums.size(); i++) {
        r -= nums[i];
        if (l == r) return i;
        l += nums[i];
    }

    return -1;
}1