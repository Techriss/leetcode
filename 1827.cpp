#include <iostream>
#include <vector>
using namespace std;

// save in array
int minOperations(vector<int>& nums) {
    int sum = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= nums[i-1]) {
            int change = nums[i-1]-nums[i]+1;
            sum += change;
            nums[i] += change;
        }
    }

    return sum;
}

// or dont
int minOperations(vector<int>& nums) {
    int res = 0, last = 0;
    for (auto &x : nums) {
        // get change
        res += max(0, last - x + 1);

        // since we dont save results after change, last is either x (the already good one) or last+1 (the x after change)
        last = max(x, last + 1);
    }
    return res;
}