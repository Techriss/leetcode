#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct hashFunction {
    size_t operator()(const vector<int> &x) const {
        return x[0] ^ x[1] ^ x[2];
    }
};

// brute (way too slow) [TLE]
vector<vector<int>> threeSum(vector<int>& nums) {
    const int n = nums.size();
    unordered_set<vector<int>, hashFunction> v;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) 
            for (int k = j+1; k < n; k++)
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> newv = vector<int>({nums[i], nums[j], nums[k]});
                    sort(newv.begin(), newv.end());
                    v.insert(newv);
                }

    
    vector<vector<int>> res;
    for (auto &x : v)
        res.push_back(x);

    return res;
}


// slightly optimized - keeping a map of already created sums of 2 numbers
// way too slow [TLE]
vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int, vector<pair<int, int>>> m;
    vector<vector<int>> v;
    const int n = nums.size();
    
    for (int j = n-1; j >= 0; j--) {
        for (int i = j-1; i >= 0; i--) {
            // let i be k

            for (auto &p : m[-nums[i]]) {
                if (i == p.first || i == p.second) continue;
                vector<int> newv = vector<int>({nums[i], nums[p.first], nums[p.second]});
                sort(newv.begin(), newv.end());
                v.push_back(newv);
            }

            m.erase(-nums[i]);
            m[nums[i] + nums[j]].push_back({i, j});
        }
    }


    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    return v;
}










// two pointers
vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > res;
    const int n = num.size();
    sort(num.begin(), num.end());

    for (int i = 0; i < n; i++) {
        // skip duplicates
        if (i > 0 && num[i-1] == num[i]) continue;
        int target = -num[i];
        int l = i+1, r = n-1;

        while (l < r) {
            int sum = num[l] + num[r];
            
            // since the array is sorted, we can easily search for the target (O(N))
            if (sum < target) l++;
            else if (sum > target) r--;
            else {
                vector<int> triplet = { num[i], num[l], num[r] };
                res.push_back(triplet);
                
                // since the array is sorted, we can process duplicates by skipping indices

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (l < r && num[l] == triplet[1]) l++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (l < r && num[r] == triplet[2]) r--;
            }
            
        }
    }
    
    return res;
}









// 2 pointers, just slightly different
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin() , nums.end());
    if (nums.size() < 3) return {};
    if (nums[0] > 0) return {};
    vector<vector<int>> answer;
    
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue; // already processed

        int low = i + 1 , high = nums.size() - 1;
        int sum = 0;

        while (low < high) {
            sum = nums[i] + nums[low] + nums[high];
            if (sum > 0) high--;
            else if (sum < 0) low--;
            else {
                answer.push_back({nums[i] , nums[low] , nums[high]});
                int last_low_occurence = nums[low], last_high_occurence = nums[high];
                while (low < high && nums[low] == last_low_occurence) low++;
                while (low < high && nums[high] == last_high_occurence) high++;
            }
        }
    }
    return answer;
}




// here are 2 pointers WIHTOUT the duplicate measures, just set
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    unordered_set<vector<int>> set;
    vector<vector<int>> res;

    for (int i = 0; i < n-2; i++){
        int low = i+1, high = n-1;
        while (low < high){
            int sum = nums[i] + nums[low] + nums[high];

            if (sum < 0) low++;
            else if (sum > 0) high--;
            else {
                set.insert({nums[i], nums[low], nums[high]});
                low++, high--;
            }
        }
    }

    for (auto it : set)
        res.push_back(it);

    return res;
}






// hashmap
// here, instead of storing the sums of 2 numbers in a hashmap, we will check for the sum and store single values
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin() , nums.end());
    if (nums.size() < 3 || nums[0] > 0) return {};

    // map keeps track of last index of element
    unordered_map<int, int> m;
    for (int i = 0 ; i < nums.size() ; ++i) {
        m[nums[i]] = i;
    }

    vector<vector<int>> answer;
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (nums[i] > 0) break;
        for (int j = i + 1; j < nums.size() - 1; ++j) {
            int required = -1*(nums[i] + nums[j]);
            if (m.count(required) && m[required] > j) {
                answer.push_back({nums[i], nums[j], required});
            }

            j = m[nums[j]]; // Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
        }

        i = m[nums[i]];    // Update i to last occurence of 1st fixed number to avoid duplicate triplets.
    }

    return answer;
}






