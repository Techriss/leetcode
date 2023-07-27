#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    long long res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        res = res ^ nums[i];
    }

    return res;
}

int main() {
    vector<int> v({1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6});
    cout << singleNumber(v) << endl;

}