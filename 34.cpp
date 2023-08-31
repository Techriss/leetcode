#include <iostream>
#include <vector>
using namespace std;

// idea: we look for leftmost target, then for rightmost target
vector<int> searchRange(vector<int>& nums, int target) {
    const int n = nums.size();
    int l = 0, r = n-1;
    int x = -1, y = -1;

    // if same or greater, resize search but update x as leftmost seen target
    while (l <= r) {
        int mid = (l+r)/2;
        
        if (nums[mid] < target) l = mid+1;
        else {
            if (nums[mid] == target) {
                // preserve rightmost seen target
                if (y == -1) y = mid;
                x = mid;
            }
            r = mid - 1;
        }
    }


    if (y == -1) return {x, y};
    l = y, r = n-1;

    // if same or less, resize search but update y as rightmost seen target
    while (l <= r) {
        int mid = (l+r)/2;
        
        if (nums[mid] > target) r = mid-1;
        else {
            if (nums[mid] == target) y = mid;
            l = mid + 1;
        }
    }

    return {x, y};
}


int main() {
    vector<int> v({});
    auto res = searchRange(v, 6);
    cout << res[0] << ", " << res[1] << endl;
}
