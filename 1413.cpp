#include <iostream>
#include <vector>
using namespace std;

// no need for prefix sums, only curr prefix sum
int minStartValue(vector<int>& A) {
    int ans = 0, sum = 0;
    for (auto &x : A)
        sum += x, ans = min(ans, sum);
    return 1-ans;
}