#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// standard map solution
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
        if (m.count(nums[i])) {
            if (abs(i - m[nums[i]]) <= k) return true;
        }

        m[nums[i]] = i;
    }

    return false;
}

int main() {

    vector<int> v({99, 99});
    cout << containsNearbyDuplicate(v, 2);
}