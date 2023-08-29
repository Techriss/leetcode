#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// from wikipedia
/*
    Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
    Find the largest index l > k such that nums[k] < nums[l].
    Swap nums[k] and nums[l].
    Reverse the sub-array nums[k + 1:].
*/


void nextPermutation(vector<int>& nums) {
    const int n = nums.size();

    int k = n-2;
    for (; k >= 0 && nums[k] >= nums[k+1]; --k);

    if (k == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int l = n-1;
    for (; l > k && nums[k] >= nums[l]; --l);

    swap(nums[k], nums[l]);
    reverse(nums.begin() + k + 1, nums.end());
}





































/*



    here is some failure
    (none of this works)    



*/
void nextPermutation(vector<int>& nums) {
    auto nums2 = nums;
    sort(nums2.begin(), nums2.end(), greater<int>());
    if (nums == nums2) {
        reverse(nums.begin(), nums.end());
        return;
    }

    sort(nums2.begin(), nums2.end());
    vector<int> curr, last;
    unordered_set<int> s;
    bool found = false;
    allperms(nums2, curr, last, s, nums, found);
    nums = last;
    return;
}





void allperms(vector<int> &nums, vector<int> &curr, vector<int> &last, unordered_set<int> &s, vector<int> &target, bool &found) {
    if (curr.size() == nums.size()) {
        if (target == last) found = true;
        last = curr;
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (s.count(i)) continue;
        auto next = curr;
        next.push_back(nums[i]);
        s.insert(i);
        allperms(nums, next, last, s, target, found);
        if (found) { cout << "exiting\n"; return; }
        s.erase(i);
    }
}

int main() {
    unordered_set<int> s;
    vector<int> nums({1, 1, 5});
    vector<int> curr, last, target({1, 5, 1});
    bool found = false;
    allperms(nums, curr, last, s, target, found);
    for (auto &x : last) cout << x << ", ";

    
}


/*

    [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]

    [3, 2, 1]

    [1, 2, 3]
    [1, 3, 2]
    [2, 1, 3]
    [2, 3, 1]


*/







// here's a helper function that displays all permutations (this actually works and is very slow)
void allperms(vector<int> &nums, vector<int> curr, vector<vector<int>> &perms, unordered_set<int> &s) {
    if (curr.size() == nums.size()) {
        perms.push_back(curr);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (s.count(i)) continue;
        auto next = curr;
        next.push_back(nums[i]);
        s.insert(i);
        allperms(nums, next, perms, s);
        s.erase(i);
    }
}