#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sort
// get three biggest, if they form a triangle (we must only check 1 inequality since we know which sides are biggest), return true
// if not, pop the biggest one

int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    while (n > 2) {
        if (nums[n-2] + nums[n-3] > nums[n-1]) return nums[n-1] + nums[n-2] + nums[n-3];
        else n--;
    }

    return 0;
}