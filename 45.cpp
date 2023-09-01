#include <iostream>
#include <vector>
using namespace std;



// -- REVISION PROCESS --

// absolute brute [TLE] O(N!)
int jump(vector<int>& nums, int pos = 0) {
	if (pos >= size(nums) - 1) return 0;        
	int minJumps = 10001;

    // for all possible jumps, try jumping
	for (int j = 1; j <= nums[pos]; j++)
		minJumps = min(minJumps, 1 + jump(nums, pos + j));     

	return minJumps;
}



// since for some positions we calculate min multiple times, we can memoize, O(N^2)
int jump(vector<int>& nums) {
	vector<int> dp(size(nums), 10001);
	return solve(nums, dp, 0);
}

int solve(vector<int>& nums, vector<int>& dp, int pos) {
	if (pos >= size(nums) - 1) return 0;
	if (dp[pos] != 10001) return dp[pos];

	for (int j = 1; j <= nums[pos]; j++)
		dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + j));   

	return dp[pos];
}


// since we can memoize, we can tabulate,  O(N^2) still
int jump(vector<int>& nums) {
	const int n = size(nums);
	vector<int> dp(n, 10001);
	dp[n - 1] = 0;

	for (int i = n - 2; i >= 0; i--) 
		for (int j = 1; i + j < n && j <= nums[i]; j++) 
			dp[i] = min(dp[i], 1 + dp[i+j]);

	return dp[0];
}


// but we can in fact do it greedily O(N)
int jump(vector<int>& nums) {
	int n = size(nums), maxReachable = 0, lastJumpedPos = 0, jumps = 0;

	for (int i = 0; lastJumpedPos < n - 1; i++) {
		maxReachable = max(maxReachable, i + nums[i]);
		if (i == lastJumpedPos) {
			lastJumpedPos = maxReachable;
			jumps++;
		}            
	}

	return jumps;
}


/*

    [2,3,1,1,4] 

    we choose the furthest possible index first, jump
    i = 0, max = 2, j = 1, l = 2;

    we discover better alternatives in the range of [0, l)
    i = 1, max = 4, i != l

    we make the best jump when arrived at l
    i = 2, max = 4, j = 2, l = 4, end

*/






















// greedy (take max) [doesn't work, let's say {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0}]
int jump(vector<int>& nums, int i = 0) {
    if (i == nums.size()-1) return 0;
    if (i + nums[i] >= nums.size()-1) return 1;
    int maxi = i+1;

    for (int j = i+1; j <= i+nums[i]; j++)
        if (nums[j] >= nums[maxi]) maxi = j;

    return jump(nums, maxi) + 1;
}


/*

3 100 10 1 0, 0, 0, 0, 0, 0, 0

*/