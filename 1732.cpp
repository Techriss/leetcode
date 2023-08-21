#include <iostream>
#include <vector>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int alt = 0, maxalt = 0;
    for (auto &x : gain) {
        alt += x;
        maxalt = max(maxalt, alt);
    }

    return maxalt;
}