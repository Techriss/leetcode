/*
    9. PALINDROME NUMBER
*/

#include <vector>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;

    vector<int> d;

    while (x > 0) {
        int digit = x % 10;
        d.push_back(digit);
        x /= 10;
    }

    int l = 0, r = d.size() - 1;
    while (l < r) {
        if (d[l] != d[r]) return false;
        l++; r--;
    }

    return true;
}