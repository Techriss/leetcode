#include <iostream>
#include <vector>
using namespace std;

// from inside
vector<int> sumZero(int n) {
    vector<int> v;
    if (n % 2 == 1) v.push_back(0);
    for (int i = 1; v.size() < n; i++) {
        v.push_back(i);
        v.push_back(-i);
    }

    return v;
}


// linearly
vector<int> sumZero(int n) {
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        A[i] = i * 2 - n + 1;
    return A;
}


/*

1: 0
2: 1 -1
3: 1 -1 0
4: 1 -1 2 -2

*/