#include <iostream>
#include <vector>
using namespace std;

int maximumProduct(vector<int>& nums) {
    int m1 = 0, m2 = 1, m3 = 2, l1 = 0, l2 = 1;
    for (int i = 0; i < nums.size(); i++) m1 = (nums[i] > nums[m1] && i != m2 && i != m3) ? i : m1;
    for (int i = 0; i < nums.size(); i++) m2 = (nums[i] > nums[m2] && i != m1 && i != m3) ? i : m2;
    for (int i = 0; i < nums.size(); i++) m3 = (nums[i] > nums[m3] && i != m1 && i != m2) ? i : m3;
    for (int i = 0; i < nums.size(); i++) l1 = (nums[i] < nums[l1] && i != l2) ? i : l1;
    for (int i = 0; i < nums.size(); i++) l2 = (nums[i] < nums[l2] && i != l1) ? i : l2;

    return max(nums[m1]*nums[m2]*nums[m3], nums[l1]*nums[l2]*max(nums[m1], max(nums[m2], nums[m3])));
} 





int maximumProduct(vector<int>& nums) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    
    for (int val : nums){
        
        if (val > max1){
            max3=max2;
            max2=max1;
            max1=val;
        } else if(val > max2){
            max3=max2;
            max2=val;
        } else if(val > max3){
            max3=val;
        }
        
        if (val < min1){
            min2=min1;
            min1=val;
        } 
        else if(val < min2){
            min2=val;
        }
    }
    
    return max(max1*max2*max3,min1*min2*max1);    
}