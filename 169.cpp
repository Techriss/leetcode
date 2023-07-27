/*
 * MOORE'S MAJORITY VOTING  
*/

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0, candidate;
    for (auto x : nums) {
        if (count == 0) candidate = x;
        if (candidate == x) count++;
        else count--;
    }

    return candidate;
}

// solution 2: map counting