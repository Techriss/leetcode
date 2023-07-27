#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    if (nums.size() <= 1) return;

    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            nums.erase(nums.begin() + i);
            i--;
            count++;
        }
    }

    while (count --> 0) nums.push_back(0);
}

// you only have to swap the leftmost 0 with the non-zero found
void moveZeroes(vector<int>& nums) {
    if (nums.size() <= 1) return;

    int l = 0, r = 0;
    while (r < nums.size()) {
        if (nums[r] != 0) swap(nums[l++], nums[r]);
        r++;
    }
}

int main() {
    vector<int> v({1, 2, 0, 0, 0, 0, 0, 4});
    moveZeroes(v);
    for (auto x : v) cout << x << " ";
}