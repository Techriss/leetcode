#include <iostream>
#include <vector>
using namespace std;

// O(2^N)
int res;

int subsetXORSum(vector<int>& nums) {
    res = 0;
    subsets(nums, 0, 0);
    return res;
}

// move through every element, get answer without including and with including it
void subsets(vector<int> &nums, int i, int xort) {
    // no more elements, the end of current combination
    if (i == nums.size()) {
        res += xort;
        return;
    }

    // combination without ith element
    subsets(nums, i+1, xort);

    // combination with ith element
    subsets(nums, i+1, xort ^ nums[i]);
}





// another way
int solve(vector<int>& nums, int level, int currXor) {

    // Base Condition
    if(level == nums.size()){
        return currXor;
    }

    int include = solve(nums, level + 1, currXor ^ nums[level]);
    int exclude = solve(nums, level + 1, currXor);

    return include + exclude;
}







// helper (base) - finding all the subsets
void solve(vector<int>& arr, vector<vector<int>>& subsets, vector<int> curr_subset, int i = 0) {
    if (i == arr.size()) {
        subsets.push_back(curr_subset);
        return;
    }

    // Include
    curr_subset.push_back(arr[i]);
    solve(arr, subsets,curr_subset, i+1);

    // Exclude
    curr_subset.pop_back();
    solve(arr, subsets,curr_subset, i+1);
}






// another method
/*

    the sum of xor totals of every subset
    is equal to to all numbers ored together
    times 2^(n-1) 

    why?? no idea

*/
int subsetXORSum(vector<int>& nums) {
    int n = nums.size();
    int bits = 0;
    for (int i = 0; i < n; i++)
        bits |= nums[i];

    int ans = bits * pow(2, n - 1);

    return ans;
}