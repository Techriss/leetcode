#include <iostream>
#include <vector>
using namespace std;

// O(N)
int findKthPositive(vector<int>& arr, int k) {
    for (int i = 1, j = 0; ; i++, j++) {
        while ((j == arr.size() || i != arr[j]) && k-- > 0) ++i;
        if (k <= 0) return i-1;
    }

    return -1;
}

// O(log N)
int findKthPositive(vector<int>& A, int k) {
    int l = 0, r = A.size(), m;

    while (l < r) {
        m = (l + r) / 2;

        // we do binary search to get (A[m] - (m+1)) which is the number of missing numbers to be the largest index when the value is smaller than k
        if (A[m] - 1 - m < k)
            l = m + 1;
        else
            r = m;
    }

    return l + k;             // arr[end] - (B[end] - k + 1)
}

// more understandable (unpacked)
int findKthPositive(vector<int>& A, int k) {
    vector<int> B = A;
    for (int i = 0; i < B.size(); i++) B[i] -= (i+1);

    int l = 0, r = B.size(), m;
    while (l < r) {
        m = (l + r) / 2;
        if (B[m] < k)
            l = m + 1;
        else
            r = m;
    }

    return l + k;
}

int main() {
    vector<int> v({2, 3, 4, 7});
    cout << findKthPositive(v, 2);
}