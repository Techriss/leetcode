/*
    BINARY SEARCH
*/



#include <iostream>
#include <vector>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1, mid = 0;
    
    while (l < r) {
        mid = (l+r)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    mid = (l+r)/2;
    cout << "mid: " << mid << endl;
    if (nums[mid] < target) return mid + 1;
    else return mid;
}

int main() {
    vector<int> v({0, 1, 2, 3});
    cout << searchInsert(v, 4) << endl;
    
}