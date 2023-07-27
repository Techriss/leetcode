#include <iostream>
#include <vector>
using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops) {
    int minx = m, miny = n;
    for (auto op : ops) {
        minx = min(minx, op[0]);
        miny = min(miny, op[1]);
    }

    return minx*miny;
}