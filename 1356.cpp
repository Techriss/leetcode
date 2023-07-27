#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// idea: brute
vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](auto &l, auto&r) {
        int dif = __builtin_popcount(l) -  __builtin_popcount(r);
        return dif == 0 ? (l < r) : (dif < 0);
    });

    return arr;
}


// hyp: same as sorting even first and odd later
// vector<int> sortByBits(vector<int>& arr) {
//     int l, r;
//     for (l = 0, r = arr.size()-1; l < r; l++) {
//         while (arr[l] % 2 == 1) swap(arr[l], arr[r--]);
//     }

//     sort(arr.begin(), arr.begin() + l);
//     sort(arr.begin() + l + 1, arr.end());

//     return arr;
// }

// int main() {
//     vector<int> v({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
//     v = sortByBits(v);
//     for (auto &x : v) cout << x << " ";
// }