#include <iostream>
#include <vector>
using namespace std;

bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    vector<int> v(52, 0);
    for (auto &r : ranges) ++v[r[0]], --v[r[1]+1];
    for (int i = 1; i <= 50; i++) v[i] += v[i-1];

    for (int i = left; i <= right; i++) {
        if (v[i] == 0) return false;
    }

    return true;
}