#include <iostream>
#include <vector>
using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    int gmax = 1, lmax = 1;
    int prev = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > prev) lmax++;
        else {
            gmax = max(lmax, gmax);
            lmax = 1;
        }

        prev = nums[i];
    }

    return max(lmax, gmax);
}