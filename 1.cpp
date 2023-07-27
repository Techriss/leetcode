/*
    1. TWO SUM
*/

#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target, unordered_map<int, int> m) {
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end() || m[nums[i] == 0]) {
                m[nums[i]] = i + 1;
            }
            if (m[target-nums[i]] != 0 && m[target-nums[i]]-1 != i) {
                return vector({m[target-nums[i]] - 1, i});
            }
        }
    }

private:
    unordered_map<int, int> m;
};



