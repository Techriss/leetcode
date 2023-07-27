#include <iostream>
#include <vector>
using namespace std;

// simply insert and pop
void duplicateZeros(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            arr.insert(arr.begin() + i, 1, 0);
            arr.pop_back();
            i++;
        }
    }
}

// create new and override
void duplicateZeros(vector<int>& arr) {
    int n = arr.size();
    vector<int> v;

    for (int i = 0; i < n; i++) {
        v.push_back(arr[i]);
        if (i < n-1 && arr[i] == 0) {
            v.push_back(0);
            n--;
        }
    }

    arr = v;
}


// another way
void duplicateZeros(vector<int>& a, int i = 0, int sh = 0) {
    const int n = a.size();
    for (i = 0; sh + i < n; ++i) sh += a[i] == 0;
    for (i = i - 1; sh > 0; --i) {
        if (i + sh < n) a[i + sh] = a[i];
        if (a[i] == 0) a[i + --sh] = a[i];
    }
}