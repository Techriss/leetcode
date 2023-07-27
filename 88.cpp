#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> v;
    int i1, i2;

    for (i1 = 0, i2 = 0; i1 < m && i2 < n;) {
        if (nums1[i1] < nums2[i2]) v.push_back(nums1[i1++]);
        else v.push_back(nums2[i2++]);
    }

    while (i1 < m) {
        v.push_back(nums1[i1++]);
    }

    while (i2 < n) {
        v.push_back(nums2[i2++]);
    }

    nums1 = v;
}

int main() {
    vector<int> v1({1, 3, 5, 7, 9});
    vector<int> v2({2, 4, 6, 8, 10});
    merge(v1, v1.size(), v2, v2.size());

    for (auto x : v1) cout << x << " "; 
}
