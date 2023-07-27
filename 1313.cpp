#include <iostream>
#include <vector>
using namespace std;


// inner loop
vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> v;
    for (int i = 0; i < nums.size(); i += 2) {
        while (nums[i] --> 0) v.push_back(nums[i+1]);
    }

    return v;
}


// or insert
vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> v;
    for (int i = 0; i < nums.size(); i += 2) {
        v.insert(v.end(), nums[i], nums[i+1]);
    }

    return v;
}