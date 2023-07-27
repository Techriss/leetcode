#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int i = 0, j = nums.size()-1; 
    while (i <= j) {
        while (nums[i] % 2 == 1) swap(nums[i], nums[j--]);
        i++;
    }

    return nums;
}