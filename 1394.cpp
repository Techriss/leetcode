#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// map
int findLucky(vector<int>& arr) {
    unordered_map<int, int> m;
    for (auto &x : arr) ++m[x];
    
    int maxv = -1;
    for (auto &p : m) if (p.first == p.second) maxv = max(maxv, p.first);
    return maxv;
}

// or if O(1) space needed, we can store counts in the array itself
// basically utilizing arr[arr[i] - 1] (just a random idea) as a connection and its "higher part" since values are limited to 500
int findLucky(vector<int>& arr) {
    for (auto n : arr) {
        n &= 0xFFFF;
        if (n <= arr.size())
            arr[n - 1] += 0x10000;
    }
    for (auto i = arr.size(); i > 0; --i)
        if ((arr[i - 1] >> 16) == i)
            return i;
    return -1;
}