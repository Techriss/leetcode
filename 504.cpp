#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string convertToBase7(int num) {
    if (num == 0) return "0";
    bool neg = num < 0;
    if (neg) num = -num;
    string s;
    while (num > 0) {
        s += to_string(num % 7);
        num /= 7;
    }

    if (neg) s += '-';

    reverse(s.begin(), s.end());
    return s;
}

int main() {
    cout << convertToBase7(6) << endl;
    cout << convertToBase7(-7) << endl;
}