#include <iostream>
using namespace std;

// recursive
int numberOfMatches(int n) {
    if (n == 1) return 0;
    return (n % 2) ? ((n-1)/2) + numberOfMatches((n-1)/2 + 1) : (n/2) + numberOfMatches(n/2);
}

// simpler
// one wins, others lose, hence n-1 matches
int numberOfMatches(int n) {
    return n-1;
}