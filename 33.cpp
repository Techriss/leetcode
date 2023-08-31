#include <iostream>
#include <vector>
using namespace std;

// idea: first find the pivot (log n) and bin search (log n) giving O(log n)
int search(vector<int>& nums, int target) {
    const int n = nums.size();
    int l = 0, r = n-1, pivot = 0, last = n-1;

    // looking for pivot
    while (l <= r) {
        int mid = (l+r)/2;
        if (mid == n-1 || nums[mid] > nums[mid+1]) { pivot = (mid + 1) % n; break; }
        if (l == r && mid == 0) { pivot = mid; break; }
        else if (nums[mid] < nums[last]) r = mid-1;
        else l = mid+1;
    }

    // adapted binsearch
    l = 0, r = n-1;
    while (l <= r) {
        int mid = (l+r)/2;
        int mid2 = (pivot + mid) % n;
        if (nums[mid2] == target) return mid2;
        else if (nums[mid2] < target) l = mid+1;
        else r = mid-1;
    }

    return -1;
}


// another way to find pivot
int search(vector<int>& nums, int target) {
    const int n = nums.size();
    int l = 0, r = n-1, pivot = 0;

    // looking for pivot
    while (l < r){
        int mid = (l+r)/2;
        if (nums[mid] > nums[r]) l = mid+1;
        else r = mid;
    }

    pivot = l;

    // adapted binsearch
    l = 0, r = n-1;
    while (l <= r) {
        int mid = (l+r)/2;
        int mid2 = (pivot + mid) % n;
        if (nums[mid2] == target) return mid2;
        else if (nums[mid2] < target) l = mid+1;
        else r = mid-1;
    }

    return -1;
}




// fancy solution
/*
    If target is let's say 14, then we adjust nums to this, where "inf" means infinity:
    [12, 13, 14, 15, 16, 17, 18, 19, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf]

    If target is let's say 7, then we adjust nums to this:
    [-inf, -inf, -inf, -inf, -inf, -inf, -inf, -inf, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
*/
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = (l + r) / 2;
        
                     // checking if both numbers are in the same 'parts' of the array
        double num = (nums[mid] < nums[0]) == (target < nums[0])
                   ? nums[mid]
                   : target < nums[0] ? -INFINITY : INFINITY;
                   
        if (num < target)
            l = mid + 1;
        else if (num > target)
            r = mid;
        else
            return mid;
    }
    return -1;
}

// 3, 4, 5, 0, 1, 2, 3