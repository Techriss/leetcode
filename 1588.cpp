#include <iostream>
#include <vector>
using namespace std;

// brute
int sumOddLengthSubarrays(vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int len = 1; i+len-1 < arr.size(); len += 2) {
            for (int j = i; j < i+len; j++) sum += arr[j];
        }
    }

    return sum;
}

// O(N)
int sumOddLengthSubarrays(vector<int>& arr) {
    int sum = 0;
    const int n = arr.size();

    // count contributions (i+1 to the left, n-i to the right)
    for (int i = 0; i < n; i++) {
        sum += (((i + 1) * (n - i) + 1) / 2) * arr[i];
    }

    return sum;
}