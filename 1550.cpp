#include <iostream>
#include <vector>
using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {
    int odds = 0;
    for (auto &x : arr) {
        if (x % 2 == 1) ++odds;
        else odds = 0;

        if (odds == 3) return true;
    }

    return false;
}