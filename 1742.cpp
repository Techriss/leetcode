#include <iostream>
#include <unordered_map>
using namespace std;

// brute
int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> m;
    int maxs = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
        int x = i, sum = 0;
        while (x > 0) sum += x%10, x /= 10;
        ++m[sum];
        maxs = max(maxs, m[sum]);
    }

    return maxs;
}

// brute but vector
int countBalls(int lowLimit, int highLimit) {
    vector<int> m(46, 0);
    int maxs = 0;
    
    for (int i = lowLimit; i <= highLimit; i++) {
        int x = i, sum = 0;
        while (x > 0) sum += x%10, x /= 10;
        ++m[sum];
        maxs = max(maxs, m[sum]);
    }

    return maxs;
}