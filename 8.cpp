#include <iostream>
using namespace std;

int myAtoi(string s) {
    long long n = 0;
    const int sn = s.size();

    int i = 0;
    while (i < sn && s[i] == ' ') ++i;
    if (i == sn) return 0;

    bool neg = false;
    if (s[i] == '-') neg = true;
    if (neg || s[i] == '+') ++i;

    while (i < sn && isdigit(s[i])) {
        n = n*10 + (s[i] - '0');
        if (n > 2147483647) return neg ? -2147483648 : 2147483647;
        ++i;
    }

    if (neg) n = -n;
    return n;
}