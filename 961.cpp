#include <iostream>
#include <vector>
using namespace std;

// obvious: unordered_set

// another option: if before or before before (must happen somewhen)
int repeatedNTimes(vector<int>& A) {
    for (int i = 2; i < A.size(); ++i)
        if (A[i] == A[i - 1] || A[i] == A[i - 2])
            return A[i];
    return A[0];
}