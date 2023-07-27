#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string addStrings(string num1, string num2) {
    int i1 = num1.size()-1, i2 = num2.size()-1, ri = 0;
    string res = "0";

    while (i1 >= 0 || i2 >= 0) {
        int sum = (int)(res[ri])-48;
        if (i1 >= 0) sum += (int)(num1[i1])-48;
        if (i2 >= 0) sum += (int)(num2[i2])-48;

        if (sum == 0) {
            res += '0';
        }
        else if (sum <= 9) {
            res[ri] = to_string(sum)[0];
            res += '0';
        }
        else {
            res[ri] = to_string(sum % 10)[0];
            res += to_string(sum/10)[0];
        }

        ri++; i1--; i2--;
    }

    if (res[ri] == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cout << addStrings("0", "0") << endl;
}