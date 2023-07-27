#include <iostream>
#include <vector>
using namespace std;

// greedy doesn't work
// hence brute force

// hence recursion
// then memoization

// vector<int> dp;

// int mincost(vector<int> &cost, int n) {
//     if (n < 0) return 0;
//     if (n == 0 || n == 1) return cost[n];
//     if (dp[n] != 0) return dp[n];

//     dp[n] = cost[n] + min(mincost(cost, n-1), mincost(cost, n-2));
//     return dp[n];
// }

// int minCostClimbingStairs(vector<int>& cost) {
//     int n = cost.size();
//     dp = vector<int>(n);
//     return min(mincost(cost, n-1), mincost(cost, n-2));
// }


// looking at the dp table and seeing it progressing in real time, we can easily change the solution to tabulation

// int minCostClimbingStairs(vector<int>& cost) {
//     int n = cost.size();
//     vector<int> dp(n);

//     for (int i = 0; i < n; i++) {
//         if (n < 2) dp[i] = cost[i];
//         else dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
//     }

//     return min(dp[n-1], dp[n-2]);
// }


// optimize space

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int c1 = cost[0], c2 = cost[1];

    for (int i = 2; i < n; i++) {
        int curr = cost[i] + min(c1, c2);
        c1 =c2;
        c2 = curr;
    }

    return min(c1, c2);
}


