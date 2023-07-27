#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    long long sum = 0, maxsum = 0;
    for (int i = 0; i < k; i++) sum += nums[i];
    maxsum = sum;
    for (int i = k; i < nums.size(); i++) {
        sum = sum - nums[i-k] + nums[i];
        maxsum = max(sum, maxsum);
    }

    return (double)maxsum/k;
}

int main() {
    vector<int> v({1,12,-5,-6,50,3});
    cout << findMaxAverage(v, 1) << endl;
}