#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// absolute brute (no way that's passing tests) [TLE]
struct hashFunction {
    size_t operator()(const vector<int> &x) const {
        return x[0] ^ x[1] ^ x[2] ^ x[3];
    }
};

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    unordered_set<vector<int>, hashFunction> s;
    const int n = nums.size();

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            for (int k = j+1; k < n; k++)
                for (int l = k+1; l < n; l++)
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        vector<int> q({nums[i], nums[j], nums[k], nums[l]});
                        sort(q.begin(), q.end());
                        s.insert(q);
                    }
    
    vector<vector<int>> v;
    for (auto &q : s)
        v.push_back(q);

    return v;
}





// two pointers (based on 3sum)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> v;
    const int n = nums.size();

    // sort the numbers first
    sort(nums.begin(), nums.end());


    // let us fix 2 numbers instead of 1 (as in 3sum)
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i+1; j < n; j++) {
            if (j > i+1 && nums[j] == nums[j-1]) continue;
            
            int l = j+1, r = n-1;
            while (l < r) {
                long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                if (sum < target) ++l;
                else if (sum > target) --r;
                else {
                    vector<int> q({nums[i], nums[j], nums[l], nums[r]});
                    v.push_back(q);

                    // skip duplicates
                    while (l < r && nums[l] == q[2]) ++l;
                    while (l < r && nums[r] == q[3]) --r;
                }
            }
        } 
    }
    

    return v;
}



// based on that, we can conclude that we can build a solution to Nsum using recursion
// to be done in another problem

