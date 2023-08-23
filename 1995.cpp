#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 0(N^4)
int countQuadruplets(vector<int>& nums) {
    int c = 0;

    for (int i = 0; i < nums.size(); i++)
        for (int j = i+1; j < nums.size(); j++)
            for (int k = j+1; k < nums.size(); k++)
                for (int l = k+1; l < nums.size(); l++)
                    if (nums[i] + nums[j] + nums[k] == nums[l]) ++c;

    return c;
}

// actually, we can go backwards, marking the already seen ds in a map
// thus reducing our complexity
// O(N^3)
int countQuadruplets(vector<int>& nums) {
    int cnt = 0;
    const int n = nums.size();
    unordered_map<int, int> seen;

    for (int c = n-1; c >= 0; c--) {
        for (int b = c-1; b >= 0; b--) {
            for (int a = b-1; a >= 0; a--) {
                int sum = nums[a] + nums[b] + nums[c];
                if (seen.count(sum)) cnt += seen[sum];
            }
        }

        // if we finish evaluating a, we can add it as a potential sum to the map
        // in other words, c may finally become some d, as now a, b and c will be further left
        seen[nums[c]]++;
    }
    
    return cnt;
}


// actually, we can go even further
// O(N^2)
int countQuadruplets(vector<int>& nums) {
    int cnt = 0;
    const int n = nums.size();
    unordered_map<int, int> seen;

    for (int a = n-1; a > 0; a--) {

        // for each pair (a+b), if a corresponding pair (d-c) was already discovered, add it to the result
        for (int b = a-1; b >= 0; b--) {
            cnt += seen[nums[a] + nums[b]];
        }

        for (int d = n-1; d > a; d--) {
            seen[nums[d] - nums[a]]++;
        }
    }
    
    return cnt;
}