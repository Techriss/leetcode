#include <iostream>
#include <vector>
using namespace std;

// simply from end
vector<int> replaceElements(vector<int>& arr) {
    vector<int> v(arr.size());
    int maxv = -1;

    for (int i = arr.size()-1; i >= 0; i--) {
        v[i] = maxv;
        maxv = max(maxv, arr[i]);
    }

    return v;
}

// exchange (returns old and sets old to new)
vector<int> replaceElements(vector<int>& A, int mx = -1) {
    for (int i = A.size() - 1; i >= 0; --i)
        mx = max(mx, exchange(A[i], mx));
    return A;
}

