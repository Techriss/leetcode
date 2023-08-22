#include <iostream>
using namespace std;

bool squareIsWhite(string coordinates) {
    return (coordinates[0]-'a') % 2 == (coordinates[1]-'0') % 2;
}

// true if sum is 0 or 2, so if sum is even, or sum of chars (sum + odd number 97+48) is odd, so

bool squareIsWhite(string coordinates) {
    return (coordinates[0] + coordinates[1]) % 2;
}

// or this, since 48 even and 97 odd, we switch version 1

bool squareIsWhite(string a) {
    return a[0] % 2 != a[1] % 2;
}