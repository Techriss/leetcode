#include <iostream>
#include <unordered_set>
using namespace std;

// look through all
bool isThree(int n) {
    int d = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            if (++d > 3) return false;
    }

    return d == 3;
}


// hyp: has to be a square of some prime
//      then it has k pairs of divisors and one unique one (the sqrt) that itselfs forms a pair [sqrt, sqrt]

bool isThree(int n) {
    unordered_set<int> p2 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
    int s = sqrt(n);
    return (n == s*s) && p2.count(s);
}