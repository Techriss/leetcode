#include <iostream>
#include <vector>
using namespace std;

int dominantIndex(vector<int>& nums) {
    int max1 = 0, max2 = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[max1]) { max2 = max1; max1 = i; }
        else if (nums[i] > nums[max2] || max1 == max2) max2 = i;
    }

    if (nums[max1] >= 2*nums[max2]) return max1;
    return -1;
}

int main() {
    vector<int> v({3, 6, 1, 0});
    cout << dominantIndex(v);

}