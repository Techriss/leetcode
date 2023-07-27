#include <iostream>
#include <vector>
using namespace std;

// basic divide
int findNumbers(vector<int>& nums) {
    int c = 0;

    for (auto &x : nums) {
        bool even = 1;
        while (x > 0) {
            even ^= 1;
            x /= 10;
        }
        c += even;
    }

    return c;
}

// or check for specific bounds
int findNumbers(vector<int>& nums) {
    int n, count=0;
    for(int i=0;i<nums.size();i++)
    {
        n=nums[i];
        if(( 10<=n && n<=99) || (1000<=n && n<=9999 ) || ( n==100000 ))
        {
            count++;
        }
    }
    return count;
}