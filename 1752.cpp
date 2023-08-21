#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int>& nums) {
    const int n = nums.size();
    int r = 0, minv = nums[0];

    // find index where sort stops, if more than 2 return false
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i-1]) {
            if (r == 0) r = i;
            else return false;
        } 
    }

    if (r == 0) return true;
    for (int i = r; i < n; i++) {
        if (nums[i] > minv) return false;
    }

    return true;
}


// find how many times does the array break asc order (1 step)
bool check(vector<int>& nums) {
    const int n = nums.size();
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i+1) % n] && ++k > 1) return false;
    }

    return true;
}

// 2 steps
bool check(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if (nums[i-1] > nums[i]) ++cnt;
    }
    if (nums[n-1] > nums[0]) ++cnt;
    return cnt <= 1;
}