#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// idea: divide array into 2 parts - positive and negative
//       they are already sorted - we only have to invert the negative part
//       merge two parts in O(N)
vector<int> sortedSquares(vector<int>& nums) {
    int neg = 0;
    while (neg < nums.size() && nums[neg] < 0) neg++;       // search where the negatives end
    for (auto &x : nums) x = x*x;                           // sqaure nums

    // merge
    vector<int> v;
    int i, j;
    for (i = neg, j = neg-1; i < nums.size() && j >= 0; ) { 
        if (nums[i] < nums[j]) v.push_back(nums[i++]);
        else v.push_back(nums[j--]);
    }

    // add leftovers
    while (i < nums.size()) v.push_back(nums[i++]);
    while (j >= 0) v.push_back(nums[j--]);

    return v;
}

// or we don't have to search the neg
vector<int> sortedSquares(vector<int>& A) {
    const int n = A.size();
    vector<int> res(n);
    int l = 0, r = n - 1;
    for (int k = n - 1; k >= 0; k--) {
        if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--];
        else res[k] = A[l] * A[l++];
    }
    return res;
}

int main() { 
    vector<int> v({-7, -5, -3, 1, 2, 3});
    auto w = sortedSquares(v);
    for (auto x : w) cout << x << " ";
}