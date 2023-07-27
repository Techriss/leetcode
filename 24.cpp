#include <iostream>
#include <vector>
using namespace std;


int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    int k = 0;
    const int n = nums.size();

    for (int l = 0, r = 1; r < nums.size(); l++, r++) {
        if (nums[l] == nums[r]) {
            nums.erase(nums.begin() + r);
            k++; l--; r--;
        }
    }

    return n-k;
}

int main() {
    vector<int> v({0, 0, 0, 0, 0});
    cout << removeDuplicates(v) << endl;
    for (auto x : v) cout << x << " ";

}