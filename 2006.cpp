#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// brute O(N^2)
int countKDifference(vector<int>& nums, int k) {
    int c = 0;
    const int n = nums.size();

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (abs(nums[i]-nums[j]) == k) ++c;

    return c;
}

// counting O(N) from backwards
// for every i, it'll look for matching already seen is
int countKDifference(vector<int>& nums, int k) {
    int c = 0;
    const int n = nums.size();
    unordered_map<int, int> m;

    for (int i = n-1; i >= 0; i--) {
        int x = nums[i] + k, y = nums[i] - k;
        c += m[x];
        c += m[y];
        ++m[nums[i]];
    }

    return c;
}

// counting O(N) forwards
// cause it doesn't matter if we start from the end, 
// the map at a certain point will only contain already seen is, and now we look for matching is for every j
int countKDifference(vector<int>& nums, int k) {
    int c = 0;
    const int n = nums.size();
    unordered_map<int, int> m;

    for (auto &x : nums) {
        c += m[x + k];
        c += m[x - k];
        ++m[x];
    }

    return c;
}

// counting O(N) but vector
// since our numbers are limited to 100, we can swap the map with a vector
// we have to however check if the keys are not out of bounds
int countKDifference(vector<int>& nums, int k) {
    int c = 0;
    const int n = nums.size();
    vector<int> m(101, 0);

    for (auto &x : nums) {
        if (x + k < 101) c += m[x + k];
        if (x > k) c += m[x - k];
        ++m[x];
    }

    return c;
}








// counting sort O(N)
// no idea if that works or not since it doesn't keep track of the current position (and i < j must be complied with)
int countKDifference(vector<int>& nums, int k) {
    int cnt[101] = {}, res = 0;
    for (auto &n : nums) ++cnt[n];
    for (int i = k + 1; i < 101; ++i)
        res += cnt[i] * cnt[i - k];
    return res;
}