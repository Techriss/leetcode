#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// we can skip the min(nums[i], nums[i+1]) since nums[i] is always smaller or the same after sorting
int arrayPairSum(vector<int>& nums) {
    int sum = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2) {
        sum += min(nums[i], nums[i+1]);
    }

    return sum;
}