#include <iostream>
#include <vector>
using namespace std;

int smallestEqual(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 9) continue; // this will perhaps speed things up
        if (nums[i] == i%10) return i;
    }

    return -1;
}