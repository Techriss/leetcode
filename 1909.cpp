#include <iostream>
#include <vector>
using namespace std;

// either remove left or right elements, check entire array again
bool canBeIncreasing(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= nums[i-1]) {
            auto v1 = nums, v2 = nums;
            v1.erase(v1.begin() + i);
            v2.erase(v2.begin() + i-1);

            return increasing(v1, max(0, i-1)) || increasing(v2, max(0, i-2));
        }
    }

    return true;
}

bool increasing(vector<int> &nums, int start) {
    for (int i = start+1; i < nums.size(); i++) {
        if (nums[i] <= nums[i-1]) return false;
    }

    return true;
}


/*
    two cases:
        either left is wrong (too small) (we simply increment)
        or right is wrong (too big) (we omit right by setting nums[i] to nums[i-1], thus next operation for new i = i+1 will compare nums[i-2] to nums[i])

*/
bool canBeIncreasing(vector<int>& nums) {
    int cnt = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] >= nums[i]) {
            if (++cnt > 1) return false;
            if (i > 1 && nums[i - 2] >= nums[i])
                nums[i] = nums[i - 1];
        }
    }
    return true;
}