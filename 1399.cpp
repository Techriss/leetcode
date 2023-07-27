#include <iostream>
#include <unordered_map>
using namespace std;

// brute
int countLargestGroup(int n) {
    unordered_map<int, int> m;
    for (int i = 1; i <= n; i++) {
        int c = 0, x = i;
        while (x > 0) {
            c += x % 10;
            x /= 10;
        }
        ++m[c];
    }

    int maxv = 0, maxc = 0;
    for (auto &x : m) {
        if (maxv == x.second) ++maxc;
        else if (maxv < x.second) { maxv = x.second; maxc = 1; }
    }

    return maxc;
}


// a little dp (worsens time)
int countLargestGroup(int n) {
    unordered_map<int, int> m;
    unordered_map<int, int> dp;
    for (int i = 1; i <= n; i++) {
        int c = dp[(i/10)] + (i%10);
        dp[i] = c;
        ++m[c];
    }

    int maxv = 0, maxc = 0;
    for (auto &x : m) {
        if (maxv == x.second) ++maxc;
        else if (maxv < x.second) { maxv = x.second; maxc = 1; }
    }

    return maxc;
}


// 
int countLargestGroup(int n) {
    vector<int> count(37,0);
    for (int i = 1; i <= n; i++){
        count[calc_sum(i)]++;
    }
    int maxi = *max_element(count.begin(), count.end());
    int ans = 0;
    for (auto i : count){
        if (i == maxi) ans++;
    }
    return ans;
}

int calc_sum(int n){
    return n==0?0:(n%10)+calc_sum(n/10);
}