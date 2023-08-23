#include <iostream>
#include <vector>
using namespace std;

// since the numbers are only positive, we only need to find 2 biggest and 2 smallest ones
int maxProductDifference(vector<int>& nums) {
    int max1 = -1, max2 = -1, min1 = INT_MAX, min2 = INT_MAX;
    for (auto &x : nums) {
        if (x > max1) max2 = max1, max1 = x;
        else if (x > max2) max2 = x;
        if (x < min1) min2 = min1, min1 = x;
        else if (x < min2) min2 = x;
    }

    return ((max1 * max2) - (min1 * min2));
}