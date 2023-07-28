#include <iostream>
#include <vector>
using namespace std;

double average(vector<int>& salary) {
    unsigned long long sum = 0;
    int maxv = -1, minv = INT_MAX;
    for (auto &x : salary) {
        sum += x;
        maxv = max(maxv, x);
        minv = min(minv, x);
    }

    return (sum-maxv-minv)/((long double)salary.size()-2);
}