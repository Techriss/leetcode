#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParityII(vector<int>& nums) {
    int i = 0, j = 1;
    const int n = nums.size();
    while (i < n && j < n) {
        while (i < n && j < n && ((nums[i] % 2) != (i % 2))) { swap(nums[i], nums[j]); j += 2; }
        i += 2;
    }

    return nums;
}