#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// idea: greedy from end
// res: greedy doens't work (its not money but numbers)
// rev: recursion
// res: beats 100% time, 97% memory

void rec(vector<vector<int>> &v, vector<int> &curr, int rest, int r, vector<int> &nums) {
    if (rest == 0) v.push_back(curr);
    if (rest <= 0 || r < 0) return;

    // try subtracting this digit (and not skipping)
    curr.push_back(nums[r]);
    rec(v, curr, rest-nums[r], r, nums);
    curr.pop_back();

    // try skipping it
    rec(v, curr, rest, r-1, nums);
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    const int n = candidates.size();
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> v;

    // first, binsearch for target
    int l = 0, r = n-1, mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (candidates[mid] < target) l = mid+1;
        else if (candidates[mid] > target) r = mid-1;
        else break;
    }

    // recurse
    vector<int> c;
    rec(v, c, target, mid, candidates);

    return v;
}





int main() {
    vector<int> v({2, 3, 5});
    auto res = combinationSum(v, 8);
    for (auto &c : res) {
        for (auto &x : c) cout << x << " + ";
        cout << endl;
    }
}












