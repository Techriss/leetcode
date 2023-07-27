#include <iostream>
#include <vector>
using namespace std;

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> v;

    for (int n = 0, i = left; i <= right; i++) {
        for (n = i; n > 0; n /= 10) {
            if (n % 10 == 0 || i % (n % 10) != 0) break;
        }

        if (!n) v.push_back(i);
    }

    return v;
}