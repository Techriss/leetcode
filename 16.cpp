#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// two pointers, without skipping duplicates
int threeSumClosest(vector<int>& nums, int target) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    int res = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n-2; i++) {
        if (i > 0 && nums[i-1] == nums[i]) continue;

        int l = i+1, r = n-1;
        while (l < r) {
            int sum = nums[l] + nums[r] + nums[i];
            int dmax = abs(target-res), d = abs(target-sum);

            if (dmax > d) res = sum;

            if (sum > target) r--;
            else if (sum < target) l++;
            else return sum;
        }
    }

    return res;
}

int main() {
    vector<int> v({-1000,-5,-5,-5,-5,-5,-5,-1,-1,-1});
    cout << threeSumClosest(v, -14) << endl;
}