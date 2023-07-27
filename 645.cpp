#include <iostream>
#include <vector>
using namespace std;

// swapping
vector<int> findErrorNums(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++){
        while (nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] != i + 1) return {nums[i], i + 1};
    }
}


// seen array
vector<int> findErrorNums(vector<int>& nums) {
    int len = nums.size();
    vector<bool> seen(len+1, false);
    vector<int> res(2);

    for (int i : nums) seen[i] = (!seen[i] || (res[0] = i));
    for (int i = 1; i <= len; i++) if (!seen[i]) return res[1] = i, res;
    return res;
}



vector<int> findErrorNums(vector<int>& nums) {
    int len = nums.size(), dup, mis;
    for (int i = 0; i < len; i++) {
        if (nums[abs(nums[i]) - 1] < 0)
            // we find duplicate instantly
            dup = abs(nums[i]);

            // negate all seen
        else nums[abs(nums[i]) - 1] *= -1;
    }
    
    for (int i = 0; i < len; i++) {
        // if not negated, not seen
        if (nums[i] > 0) {
            mis = i + 1;
            break;
        }
    }
    return {dup, mis};
}


int main() {
    vector<int> nums({1, 2, 2, 4});
    auto v = findErrorNums(nums);
    cout << v[0] << v[1] << endl;
}

