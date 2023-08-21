#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sort, get from max one by one
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [&](auto l, auto r) {
        return l[1] > r[1];
    });

    int units = 0;
    for (int i = 0; truckSize > 0 && i < boxTypes.size(); i++) {
        while (boxTypes[i][0] > 0 && truckSize > 0) { units += boxTypes[i][1]; truckSize--; boxTypes[i][0]--; }
    }

    return units;
}   

// add by chunks
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [&](auto l, auto r) {
        return l[1] > r[1];
    });

    int units = 0;
    for (int i = 0; truckSize > 0 && i < boxTypes.size(); i++) {
        int x = min(boxTypes[i][0], truckSize);
        units += x*boxTypes[i][1];
        truckSize -= x;
        if (truckSize == 0) break;
    }

    return units;
}   

// counting sort (up to 1000)
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int units = 0;
    vector<int> v(1001, 0);
    for (auto &x : boxTypes) v[x[1]] += x[0];

    for (int i = 1000; i >= 1; i--) {
        if (v[i] == 0) continue;
        int x = min(truckSize, v[i]);
        units += x*i;
        truckSize -= x;
        if (!truckSize) break;
    }

    return units;
}