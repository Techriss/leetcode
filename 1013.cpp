#include <iostream>
#include <vector>
using namespace std;

// idea
// find sum of all, divide by 3, strive to achieve it
bool canThreePartsEqualSum(vector<int>& arr) {
    // compute sum, divide by 3
    int thirdsum = 0, counter = 0;
    for (auto &x : arr) thirdsum += x;
    if (thirdsum % 3 != 0) return false;    // early exit if cannot be done
    thirdsum /= 3;

    // for every num
    int lsum = 0;
    for (auto &x : arr) {
        // add to sum
        lsum += x;

        // if achieved sum, counter++
        if (lsum == thirdsum) { lsum = 0; ++counter; }
    }

    // if some was achieved 3 times (normal) or more (0s)
    return counter >= 3;
}



// or two pointers
bool canThreePartsEqualSum(vector<int> arr) {
    int thirdsum = 0;
    for (auto &x : arr) thirdsum += x;
    if (thirdsum % 3 != 0) return false;
    thirdsum /= 3;

    int l = 0, r = arr.size() - 1; 
    int leftSum = arr[l++], rightSum = arr[r--];
    do {
        if (leftSum != thirdsum)
            leftSum += arr[l++];
        if (l < r && rightSum != thirdsum)
            rightSum += arr[r--];
        if (l <= r && leftSum == thirdsum && rightSum == thirdsum)
            return true;
    } while (l < r);
    return false;        
}