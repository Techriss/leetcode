#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> v(nums.size());
    unsigned long long n = 0;
    for (int i = 0; i < nums.size(); i++) {
        // to "append" a bit to the end, we multiply by 2 (leftshift by 1)
        // we only keep remainder as the rest will not influence the new remainder
        n = (n % 5)*2 + nums[i];
        v[i] = n % 5 == 0;
    }

    return v;
}