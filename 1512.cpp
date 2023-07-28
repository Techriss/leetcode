#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// map and sum
int numIdenticalPairs(vector<int>& nums) {
    int res = 0;
    unordered_map<int, int> m;
    for (auto &x : nums) ++m[x];
    for (auto &x : m) res += (x.second*(x.second-1))/2;
    return res;
}

// real time
int numIdenticalPairs(vector<int>& nums) {
    int res = 0;
    unordered_map<int, int> count;
    for (int &x : nums) {
        res += count[x]++;
    }
    return res;
}