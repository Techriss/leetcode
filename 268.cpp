#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    unsigned int sum = 0;
    for (auto x : nums) sum += x;
    int n = nums.size();
    return ((n*(n+1))/2) - sum;
}

int main() {
    vector<int> v({0, 1, 2, 3, 5, 6, 7, 8, 9});
    cout << missingNumber(v) << endl;
}