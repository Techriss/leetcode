#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// we can find all first occurs and all last occurs and get max value
int maxDistance(vector<int>& colors) {
    unordered_map<int, int> first, last;
    for (int i = 0; i < colors.size(); i++) {
        if (first.find(colors[i]) == first.end()) first[colors[i]] = i;
        last[colors[i]] = i;
    }

    int maxv = 0;

    for (auto &h1 : first) {
        for (auto &h2 : last) {
            if (h1.first != h2.first) maxv = max(maxv, max(abs(h2.second-h1.second), abs(last[h1.first] - first[h2.first])));
        }
    }

    return maxv;
}


// but actually, our result will always include the first house that is not like the absolute last (n-1)
// or the last that is not the absolute first (0)
// so we can simply do 2 checks and compare the results
int maxDistance(vector<int>& A) {
    int n = A.size(), i = 0, j = n - 1;
    while (A[0] == A[j]) j--;
    while (A[n - 1] == A[i]) i++;
    return max(n - 1 - i, j);
}


// if its better to traverse whole array once, we can do so
int maxDistance(vector<int>& A) {
    int res = 0, n = A.size();
    for (int i = 0; i < n; ++i) {
        if (A[i] != A[0]) res = max(res, i);
        if (A[i] != A[n - 1]) res = max(res, n - 1 - i);
    }
    return res;
}