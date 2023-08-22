#include <iostream>
#include <vector>
using namespace std;

// prefix sums after marking starts and ends of ranges
int maximumPopulation(vector<vector<int>>& logs) {
    vector<int> v(101); // 1950-2050
    for (auto &p : logs) ++v[p[0]-1950], --v[p[1]-1950];
    int maxy = 0;

    for (int i = 1; i <= 100; i++) {
        v[i] += v[i-1];
        if (v[i] > v[maxy]) maxy = i;
    }

    return maxy + 1950;
}


// 1 0 0 -1 0
// 1 1 1 0  0