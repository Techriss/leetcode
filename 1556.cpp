#include <iostream>
#include <string>
using namespace std;

// count every 3
string thousandSeparator(int n) {
    int d = 0;
    string num = "";

    if (n == 0) return "0";

    while (n > 0) {
        if (d == 3) {
            d = 0;
            num += '.';
        }

        num += to_string(n % 10);
        ++d;

        n /= 10;
    } 

    reverse(num.begin(), num.end());
    return num;
}


// or see size
string thousandSeparator(int n) {
    string s = to_string(n), res = "";
    const int sn = s.size();
   
    for (int i = 0; i < sn; i++) {
        if (i > 0 && (sn - i) % 3 == 0) res += '.';
        res += s[i];
    }

    return res;
}