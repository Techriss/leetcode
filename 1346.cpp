#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// separate
bool checkIfExist(vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    int zeros = 0;
    for (auto &x : arr) if (!x) ++zeros;
    for (auto &x : arr) if ((x && s.count(2*x)) || (!x && zeros > 1)) return true;
    return false;
}

// or joined with early returns
bool checkIfExist(vector<int>& arr) {
    unordered_set<int> set;
    for (auto &x : arr){
        // if there's 2x big of 2x smaller already (even 0) true
        if (set.count(2 * x) || ((x % 2 == 0) && set.count(x / 2)))
            return true;
        set.insert(x);
    }
    return false;
}


// or sort + binary search