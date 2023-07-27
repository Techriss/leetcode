#include <iostream>
#include <math.h>
#include <string>
using namespace std;

// logs and math
int maximum69Number (int num) {
    int l = log10(num);
    for (int i = l; i >= 0; i--) {
        int p = pow(10, i);
        if ((num / p) % 10 == 6) {
            num += 3*p;
            return num;
        }
    } 

    return num;
}

// strings
int maximum69Number (int num) {
    string s_num = to_string(num);
    for (auto &c : s_num) {
        if (c == '6') {
            c = '9';
            break;
        }
    }
    return stoi(s_num);
}