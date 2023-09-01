#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// we can use a set to keep track of put elements
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> v;
    unordered_set<int> currset;
    vector<int> curr;
    rec(nums, curr, currset, v);
    return v;
}

void rec(vector<int> &nums, vector<int> &curr, unordered_set<int> &currset, vector<vector<int>> &v) {
    if (curr.size() == nums.size()) { v.push_back(curr); return; }

    for (int i = 0; i < nums.size(); i++) {
        if (currset.count(nums[i])) continue;
        currset.insert(nums[i]);
        curr.push_back(nums[i]);
        rec(nums, curr, currset, v);
        currset.erase(nums[i]);
        curr.pop_back();
    }
}



// or use one of the greatest tricks ever seen
// we can swap the numbers to mark it as taken, making it unavailable for next function call (since it is at nums[begin] and fcall starts at begin+1)
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > v;
    permuteRecursive(num, 0, v);
    return v;
}

void permuteRecursive(vector<int> &num, int begin, vector<vector<int>> &v)	{
    if (begin >= num.size()) {
        v.push_back(num);
        return;
    }
    
    for (int i = begin; i < num.size(); i++) {
        swap(num[begin], num[i]);
        permuteRecursive(num, begin + 1, v);
        swap(num[begin], num[i]);
    }
}