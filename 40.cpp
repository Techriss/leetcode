#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// similar to combination sum I, slower
void rec(vector<vector<int>> &v, vector<int> &nums, vector<int> &curr, int rest, int i) {
    if (rest == 0) v.push_back(curr);
    if (rest <= 0 || i < 0) return;

    curr.push_back(nums[i]);
    rec(v, nums, curr, rest - nums[i], i-1);
    curr.pop_back();

    // avoiding duplicates (could implement binsearch but didn't work)
    while (i > 0 && nums[i] == nums[i-1]) --i;

    rec(v, nums, curr, rest, i);
}

// bin search to target, recurse
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> v;
    const int n = candidates.size();
    sort(candidates.begin(), candidates.end());

    int l = 0, r = n-1, mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (candidates[mid] < target) l = mid+1;
        else if (candidates[mid] > target) r = mid-1;
        else break;
    }

    vector<int> curr;
    rec(v, candidates, curr, target, mid);
    return v;
}




// hybrid (binsearch + for loop)
// works (beats 100%)
void rec(vector<vector<int>> &v, vector<int> &nums, vector<int> &curr, int rest, int i) {
    if (rest == 0) v.push_back(curr);
    if (rest <= 0 || i < 0) return;

    for (int j = i; j >= 0; j--) {
        // skipping duplicates 'next time' 
        /*
            if it is the first occurance of a number from the right, go through the whole tree
            trying all numbers to its left

            but if it is not, skip making the tree cause we've saved what happens then already
        */
        if (j < i && nums[j] == nums[j+1]) continue;

        // try nums[j], if not move on
        // backtracking is done with the for loop, not another function call
        curr.push_back(nums[j]);
        rec(v, nums, curr, rest - nums[j], j-1);
        curr.pop_back();

        // here, it backtracks
    }
}

// binsearch to target, recurse
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> v;
    const int n = candidates.size();
    sort(candidates.begin(), candidates.end());

    int l = 0, r = n-1, mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (candidates[mid] < target) l = mid+1;
        else if (candidates[mid] > target) r = mid-1;
        else break;
    }

    vector<int> curr;
    rec(v, candidates, curr, target, mid);
    return v;
}






// for loop only (a bit slower)
void rec(vector<vector<int>> &v, vector<int> &nums, vector<int> &curr, int rest, int start) {
    if (rest == 0) v.push_back(curr);
    if (rest <= 0) return;

    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i-1]) continue;
        curr.push_back(nums[i]);
        rec(v, nums, curr, rest - nums[i], i+1);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> v;
    sort(candidates.begin(), candidates.end());
    vector<int> curr;
    rec(v, candidates, curr, target, 0);
    return v;
}