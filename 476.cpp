#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int findComplement(int num) {
    unsigned mask = ~0;
    while (mask & num) mask <<= 1; // cant just flip, have to delete leading 1s (which came from leading 0s)
    return ~num ^ mask;
}

void bin(int num) {
    string s = "";
    while (num > 0) {
        s += to_string(num % 2);
        num /= 2;
    }

    reverse(s.begin(), s.end());
    cout << s << endl;
}

int main() {
    bin(5); bin(findComplement(5));
    bin(1); bin(findComplement(1));
    cout << findComplement(5) << endl;
    cout << findComplement(1) << endl;
}