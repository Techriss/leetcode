#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// sort, pop max1
vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> v;
    int sum = 0, total = 0;
    for (auto &x : nums) total += x;
    total /= 2;

    for (int i = 0; sum <= total; i++) {
        v.push_back(nums[i]);
        sum += nums[i];
    }

    return v;
}

// counting sort
vector<int> minSubsequence(vector<int>& nums) {
    vector<int> count(101, 0);
    vector<int> v;
    int total = 0;
    for (auto &x : nums) {
        ++count[x];
        total += x;
    }

    int sum = 0;
    for (int i = 100; sum <= (total-sum); i--) {
        if (count[i] > 0) { sum += i; v.push_back(i); count[i]--; }
        if (count[i] > 0) ++i;
    }

    return v;
}

// priority queue
vector<int> minSubsequence(vector<int>& nums) {
    vector<int> res;
    int total = 0;
    for (auto &x : nums) total += x;
    auto sub_sum = 0, half_sum = total/2;

    priority_queue<int> pq(begin(nums), end(nums));
    while (sub_sum <= half_sum) {
        res.push_back(pq.top());
        sub_sum += res.back();
        pq.pop();
    }

    return res;
}