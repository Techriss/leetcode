#include <iostream>
#include <vector>
using namespace std;

// from inside outwards (<= O(N))
int getMinDistance(vector<int>& nums, int target, int start) {
    for (int i = start, j = start; i >= 0 || j < nums.size(); i--, j++) {
        if (i >= 0 && nums[i] == target) return start-i;
        if (j <= nums.size() && nums[j] == target) return j-start;
    }

    return -1;
}

// from start (always O(N))
int getMinDistance(vector<int>& nums, int target, int start) {
    int ans=INT_MAX;
    for(int i=0;i<nums.size();i++){
        if (nums[i]==target){
            ans=min(ans,abs(i-start));
        }
    }
    return ans;
}