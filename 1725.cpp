#include <iostream>
#include <vector>
using namespace std;

int countGoodRectangles(vector<vector<int>>& rectangles) {
    int maxlen = 0, n = 0;
    for (auto &x : rectangles) {
        int len = min(x[0], x[1]);
        if (len == maxlen) n++;
        else if (len > maxlen) {
            maxlen = len;
            n = 1;
        }
    }

    return n;
}