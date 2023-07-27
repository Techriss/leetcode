#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute
int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int c = 0;
    for (auto &x : arr1) {
        bool good = true;
        for (auto &y : arr2) {
            if (abs(x-y) <= d) { good = false; break; }
        }

        if (good) c++;
    }

    return c;
}


// nlogn
int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(arr2.begin(), arr2.end());
    int c = 0;

    for (auto &x : arr1) {
        int l = 0, r = arr2.size()-1;
        bool good = true;
        while (l <= r) {
            int mid = (l+r)/2;
            if (arr2[mid] <= x+d && arr2[mid] >= x-d) { good = false; break; }
            else if (arr2[mid] <= x-d) l = mid+1;
            else if (arr2[mid] >= x+d) r = mid-1;
        }

        if (good) c++;
    }

    return c;
}


// binsearch v2
int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
    sort(begin(B), end(B));
    int ans = 0;
    for (int n : A) {
        if (upper_bound(begin(B), end(B), n + d) == lower_bound(begin(B), end(B), n - d)) ++ans;
    }
    return ans;
}