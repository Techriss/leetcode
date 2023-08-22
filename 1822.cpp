#include <iostream>
#include <vector>
using namespace std;

int arraySign(vector<int>& nums) {
    bool pos = true;
    for (auto &x : nums) {
        if (x == 0) return 0;
        if (x < 0) pos ^= 1;
    }

    return pos ? 1 : -1;
}