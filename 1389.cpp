#include <iostream>
#include <vector>
using namespace std;

// simulation [somehow beats 100%]
vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> target(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        target.insert(target.begin() + index[i], nums[i]);
    }

    return target;
}

// or find smaller elements after self (another problem) [may be done in nlogn]