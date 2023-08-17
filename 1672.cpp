#include <iostream>
#include <vector>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int maxv = 0, v = 0;
    for (auto &a : accounts) {
        for (auto &b : a) v += b;
        maxv = max(maxv, v);
        v = 0;
    }
        
    return maxv;
}