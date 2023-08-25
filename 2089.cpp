#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// nlogn
vector<int> targetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> targets;
    int i = 0, n = nums.size();
    while (i < n && nums[i] < target) ++i;
    while (i < n && nums[i] == target)
        targets.push_back(i++);

    return targets;
}

// counting sort
vector<int> targetIndices(vector<int>& nums, int target) {
    vector<int> v(101, 0);
    vector<int> targets;

    for (auto &x : nums) ++v[x];

    for (int x = 1, i = 0; x <= 100; x++) {
        if (x < target) i += v[x];
        else if (x == target)
            while (v[x] --> 0)
                targets.push_back(i++);

        else break;
    }

    return targets;
}


// but actually, we only have to know the number of target xs and how many numbers are less than the target to get all the indices
vector<int> targetIndices(vector<int>& nums, int target) {
    vector<int> targets;
    int less = 0, equal = 0;

    for (auto &x : nums) {
        if (x < target) ++less;
        else if (x == target) ++equal;
    }

    // less is at first the first index of a target
    for (int i = 0; i < equal; i++)
        targets.push_back(less++);

    return targets;
}