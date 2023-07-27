#include <iostream>
#include <vector>
using namespace std;

bool kLengthApart(vector<int>& nums, int k) {
    int last1 = 0;
    for (int i = 0; i < nums.size(); i++) if (nums[i] == 1) { last1 = i; break; }
    for (int i = last1 + 1; i < nums.size(); i++) {
        if (nums[i] == 1) {
            if (i-last1 <= k) return false;
            last1 = i;
        } 
    }

    return true;
}