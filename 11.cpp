#include <iostream>
#include <vector>
using namespace std;

// brute (too slow) [TLE]
int maxArea(vector<int>& height) {
    int maxv = 0;

    for (int i = 0; i < height.size(); i++)
        for (int j = i+1; j < height.size(); j++)
            maxv = max(maxv, (j-i) * min(height[i], height[j]));

    return maxv;
}


// greedy but keep the max
int maxArea(vector<int>& height) {
    int maxv = 0;

    for (int l = 0, r = height.size()-1; l < r; ) {
        maxv = max(maxv, (r-l)*min(height[l], height[r]));
        if (height[l] < height[r]) ++l;
        else --r;
    }

    return maxv;
}