#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    for (int i = 1, j = 0; ; i++, j++) {
        while ((j == arr.size() || i != arr[j]) && k-- > 0) ++i;
        if (k <= 0) return i-1;
    }

    return -1;
}

int main() {
    vector<int> v({2, 3, 4, 7});
    cout << findKthPositive(v, 2);
}