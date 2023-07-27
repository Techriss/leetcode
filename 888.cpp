#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;

// two sets 
vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    int s1 = 0, s2 = 0;
    unordered_set<int> sa, sb;

    for (auto &x : aliceSizes) { s1 += x; sa.insert(x); }
    for (auto &x : bobSizes) { s2 += x; sb.insert(x); }
    int diff = (s2-s1)/2;

    for (auto &x : sa) {
        // s1-x+y = s2+x-y
        // s1 + 2y = s2 + 2x
        // y = diff + x
        if (sb.count(diff + x)) return { x, diff+x };
    }

    return {0, 0};
}

// or one set
vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    int s1 = 0, s2 = 0;
    unordered_set<int> sa;

    for (auto &x : aliceSizes) { s1 += x; sa.insert(x); }
    for (auto &x : bobSizes) s2 += x;
    int diff = (s2-s1)/2;

    for (auto x : bobSizes) {
        if (sa.count(diff + x)) return { x, diff+x };
    }

    return {0, 0};
}

vector<int> fairCandySwap(vector<int> A, vector<int> B) {
    int dif = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
    unordered_set<int> S(A.begin(), A.end());
    for (int b: B)
        if (S.count(b + dif))
            return {b + dif, b};
    return {0, 0};
}