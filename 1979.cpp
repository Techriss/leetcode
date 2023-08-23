#include <iostream>
#include <vector>
using namespace std;

int findGCD(vector<int>& nums) {
    int maxv = nums[0], minv = nums[0];
    for (auto &x : nums) maxv = max(maxv, x), minv = min(minv, x);
    return gcd(minv, maxv);
}

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}




