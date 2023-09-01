#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> v;
    permuteRecursive(nums, 0, v);
    return v;
}


// NOTE: num is copied, not referenced, hence later (inner) swaps will not impact the backtracking
//       and thus we can remove the second swap
void permuteRecursive(vector<int> num, int begin, vector<vector<int>> &v) {
    if (begin >= num.size()) {
        v.push_back(num);
        return;
    }
    
    for (int i = begin; i < num.size(); i++) {
        if (i != begin && num[i] == num[begin]) continue;
        swap(num[begin], num[i]);
        permuteRecursive(num, begin + 1, v);
    }
}





// or set
// this set does not influcence the inner fcall, it simply blocks next permutations from using the same number in the same place
void permuteUniqueHelper(int i, vector<int>& nums, vector<vector<int>>& result) {
    if (i == nums.size()) { result.emplace_back(nums); return; }
    unordered_set<int> st;
    for (int j = i; j < nums.size(); ++j) {
        if (st.count(nums[j]) == 1) { continue; }
        st.insert(nums[j]);
        swap(nums[i], nums[j]);
        permuteUniqueHelper(i + 1, nums, result);
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int> > result;
    permuteUniqueHelper(0, nums, result);
    return result;
}