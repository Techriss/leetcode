#include <iostream>
#include <vector>
using namespace std;

// simply min of odd and even positions
int minCostToMoveChips(vector<int>& position) {
    vector<int> v(2, 0);
    for (auto &x : position) ++v[x%2];

    return min(v[0], v[1]);
}