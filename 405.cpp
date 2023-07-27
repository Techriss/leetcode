#include <iostream>
#include <algorithm>
using namespace std;

string toHex(int num) {
    if (num == 0) return "0";
    string hex = "";
    unsigned int unum = num;

    while (unum > 0) {
        int r = (unum % 16);

        if (r <= 9) hex += (char)(r+48);
        else hex += (char)(r+87);

        unum /= 16;
    }


    reverse(hex.begin(), hex.end());
    return hex;
}


int main () {
    cout << toHex(-1) << endl;
}