#include <iostream>
#include <vector>
using namespace std;

// O(N) space
vector<int> buildArray(vector<int>& nums) {
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++) ans[i] = nums[nums[i]];
    return ans;
}


// O(1) space (store in remaining bits since max value is 10000 (and 2^14 is ~16000))
vector<int> buildArray(vector<int>& nums) {
    int mask = 0b00000000000000000011111111111111;

    for (int i = 0; i < nums.size(); i++)
        nums[i] <<= 14;

    for (int i = 0; i < nums.size(); i++)
        nums[i] |= nums[nums[i] >> 14] >> 14;

    for (int i = 0; i < nums.size(); i++)
        nums[i] &= mask;

    return nums;
}

// another bit shifting solution (since its not the first time we see nums[nums[i]] but its always the first we see nums[i])
vector<int> buildArray(vector<int>& nums) {
    int mask = 0b00000000000000000011111111111111;

    for (int i = 0; i < nums.size(); i++)
        nums[i] |= (nums[nums[i]] & mask) << 14;

    for (int i = 0; i < nums.size(); i++)
        nums[i] >>= 14;

    return nums;
}

// O(1) space
vector<int> buildArray(vector<int>& nums) {
    const int q = nums.size();
    for (int i = 0; i < q; i++) {
        // base value
        int r = nums[i];

        // if not seen, returns base value (since its always smaller than q)
        // if seen, also returns base value (since the new value is multiplied by q, so its all omitted when searching for remainder)
        int b = nums[nums[i]] % q;

        nums[i] = q*b + r;
    }

    // for every element, get its result from division by q, thus omitting the remainder (og value) and returning new value
    for (int i = 0; i < q; i++)
        nums[i] /= q;

    return nums;
}

// O(1) condensed
vector<int> buildArray(vector<int>& nums) {
    const int q = nums.size();
    for (int i = 0; i < q; i++) 
        nums[i] += q*(nums[nums[i]] % q);

    for (int i = 0; i < q; i++)
        nums[i] /= q;

    return nums;
}


/*

def buildArray(nums: List[int]) -> List[int]:
  q = len(nums)
  for i,c in enumerate(nums):
    nums[i] += q * (nums[c] % q)
  for i,_ in enumerate(nums):
    nums[i] //= q
  return nums

*/


/*

    [0,2,1,5,3,4]
    [0,1,2,4,5,3]

    [0, 0]
    [2, 1]
    [1, 2]
    [5, 4]
    [3, 5]
    [4, 3]
    
*/