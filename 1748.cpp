#include <iostream>
#include <vector>
using namespace std;

int sumOfUnique(vector<int>& nums) {
    vector<int> v(101, 0);
    int sum = 0;
    for (auto &x : nums) {
        if (v[x] == 0) sum += x; 
        else if (v[x] == 1) sum -= x;
        ++v[x];
    }
    return sum;
}