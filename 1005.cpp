#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    int minabs = INT_MAX;

    for (int i = 0; i < nums.size(); i++, k--) {
        // negatives (invert)
        if (k > 0 && nums[i] <= 0) sum += -nums[i];
        // first positive
        else if (k > 0 && nums[i] > 0) {
            // if even, we can negate twice till k = 0, res stays the same
            if (k % 2 == 0) sum += nums[i];
            // if odd, we have to either add the last negative element (or zero) twice (to ovverride last negation) or subtract the first positive element
            else if (i > 0) {
                if (abs(nums[i-1]) < nums[i]) {
                    sum += nums[i];
                    sum += 2*nums[i-1];
                }
                else sum += -nums[i];
            }
            // if its first, we have no choice
            else sum += -nums[i];
            // and k is exhausted (1 + an even number (no change))
            k = 0;
        }
        // positives (leave as is)
        else sum += nums[i];
        minabs = min(abs(nums[i]), minabs);
    }

    // if k > n and odd, subtract smallest element by abs value (with override)
    if (k > 0 && k % 2 == 1) {
        sum -= 2*minabs;
    }

    return sum;
}