#include <iostream>
#include <vector>
using namespace std;

// prefix sum
vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) nums[i] += nums[i-1];
    return nums;
}