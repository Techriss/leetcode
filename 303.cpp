#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (nums.size() <= 1) {
            psums = nums;
            return;
        }

        psums = vector<int>(nums.size());
        psums[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            psums[i] = psums[i-1] + nums[i];
        }

        for (auto x : psums) cout << x << " ";
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return psums[right];
        return psums[right] - psums[left-1];
    }
private:
    vector<int> psums;
};

int main() {
    vector<int> nums({1, 2, 3, 4, 5});
    NumArray* na = new NumArray(nums);
}