#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_set<int> s;
    for (int i = 1; i <= nums.size(); i++) s.insert(s.end(), i);
    for (auto x : nums) s.erase(x);
    return vector<int>(s.begin(), s.end());
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> v;
    unordered_set<int> s(nums.begin(), nums.end());
    for (int i = 1; i <= nums.size(); i++) if (s.find(i) == s.end()) v.push_back(i);
    return v;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    for (auto &c : nums) 
        while (nums[c-1] != c) 
            swap(c, nums[c-1]);               // swap till correct index place of c is not occupied by c itself
    for (int i = 1; i <= size(nums); i++)
        if (i != nums[i-1]) ans.push_back(i);  // correct index place of i is not occupied by i itself

    return ans;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    for (auto c : nums)
        nums[abs(c)-1] = -abs(nums[abs(c)-1]);   // mark c is present by negating nums[c-1]
    for (int i = 0; i < size(nums); i++) 
        if (nums[i] > 0) ans.push_back(i+1);      // nums[i] > 0 means i+1 isnt present in nums
    return ans;
}


int main() {
    vector<int> v({1, 1});
    auto w = findDisappearedNumbers(v);
    for (auto x : w) cout << x << " ";
}