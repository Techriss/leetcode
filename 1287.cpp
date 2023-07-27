#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// maps
int findSpecialInteger(vector<int>& arr) {
    const int q = arr.size()/4;
    unordered_map<int, int> m;
    for (auto &x : arr) {
        if (++m[x] > q) return x;
    }

    return -1;
}


// but its sorted
int findSpecialInteger(vector<int>& arr) {
    const int q = arr.size()/4;

    for (int i = 1, c = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i-1]) ++c;
        else c = 1;
        if (c > q) return arr[i];
    }

    return arr[0];
}

// or candidates (our target must either be at 1/4, 1/2 or 3/4)
int findSpecialInteger(vector<int>& arr) {
    const int n = arr.size();
    vector<int> candidates = {arr[n/4], arr[n/2], arr[n*3/4]};
    for (auto &cand : candidates) {
        auto st = lower_bound(arr.begin(), arr.end(), cand);
        auto ed = upper_bound(arr.begin(), arr.end(), cand);
        if (4 * (distance(st, ed)) > n) // same as dist > n/4
            return cand;
    }
    return -1;
}


// or always check i + n/4
int findSpecialInteger(vector<int>& arr) {
    const int q = arr.size() / 4;
    for (int i = 0; i <= q*3; i++){
        if (arr[i] == arr[i + q]) return arr[i];
    }
    
    return arr[0];
} 