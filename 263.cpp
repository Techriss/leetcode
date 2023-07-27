#include <iostream>
#include <vector>
using namespace std;

bool prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

bool isUgly(int n) {
    if (n < 0) return false;
    for (unsigned int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            cout << "i: " << i << endl;
            if (prime(i) && i != 2 && i != 3 && i != 5) return false;
            int j = n/i;
            if (prime(j) && j != 2 && j != 3 && j != 5) return false;
        }
    }

    return true;
}

// way faster
bool isUgly(int n) {
    if (n <= 0) return false;

    while (n % 5 == 0) n /= 5;
    while (n % 3 == 0) n /= 3;
    while (n % 2 == 0) n /= 2;

    return n == 1;
}



int main() {
    cout << isUgly(49) << endl;
}