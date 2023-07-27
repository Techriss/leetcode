#include <iostream>
#include <vector>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    const int n = candies.size();
    vector<bool> v(n);
    int maxv = 0;
    for (auto &x : candies) maxv = max(maxv, x);
    for (int i = 0; i < n; i++) v[i] = candies[i] + extraCandies >= maxv;
    return v;
}