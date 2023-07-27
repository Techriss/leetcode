#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int gmax = 0;
    int lmax = 0;
    for (auto x : nums) {
        if (x == 1) lmax++;
        else {
            gmax = max(lmax, gmax);
            lmax = 0;
        }
    }

    return max(lmax, gmax);
}