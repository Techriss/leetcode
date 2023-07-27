#include <iostream>
#include <vector>
using namespace std;


// sieve of erastothenes
int numPrimeArrangements(int n) {
    int primes = 0;
    vector<bool> v(n+1, true);

    // sieve doing its work counting primes up to n
    for (int i = 2; i*i <= n; i++) {
        if (!v[i]) continue;
        for (int j = i*2; j <= n; j += i) {
            v[j] = false;
        }
    }  

    // count the primes
    for (int i = 2; i <= n; i++) {
        if (v[i]) primes++;
    }

    // res = primes! * rest!
    int res = 1;
    for (int i = 1; i <= primes; ++i) res = (1LL*res*i) % 1000000007;
    for (int i = 1; i <= (n-primes); ++i) res = (1LL*res*i) % 1000000007;

    return res;
}



int main() {
     cout << numPrimeArrangements(5) << endl;
}