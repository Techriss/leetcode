#include <iostream>
#include <vector>
using namespace std;

bool isMonotonic(vector<int>& nums) {
    int dir = 0, i;

    for (i = 1; i < nums.size(); i++) {
        if (nums[i-1] != nums[i]) break;
    }
    if (i == nums.size()) return true;

    dir = nums[i-1] < nums[i] ? 1 : -1;

    for (i = i+1; i < nums.size(); i++) {
        cout << nums[i-1] << " vs " << nums[i] << endl;
        if (nums[i-1]*dir > nums[i]*dir) return false;
    }

    return true;
}

// or both at the same time
bool isMonotonic(vector<int> A) {
    bool inc = true, dec = true;
    for (int i = 1; i < A.size(); ++i) {
        inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
    }
    return inc || dec;
}
