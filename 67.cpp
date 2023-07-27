#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    string res = "0";
    int ri = 0;
    int ai = a.size()-1;
    int bi = b.size()-1;

    while (ai >= 0 && bi >= 0) {
        int sum = (int)(a[ai])-48 + (int)(b[bi])-48 + (int)(res[ri])-48;
        if (sum == 0) {
            res += "0";
        } 
        else if (sum == 1) {
            res[ri] ='1';
            res += "0";
        }
        else if (sum == 2) {
            res[ri] = '0';
            res += "1";
        }
        else {
            res[ri] = '1';
            res += "1";
        }

        ri++; ai--; bi--;
    }
    
    while (ai >= 0) {
        int sum = (int)(a[ai])-48 + (int)(res[ri])-48;
        if (sum == 0) {
            res += "0";
        } 
        else if (sum == 1) {
            res[ri] ='1';
            res += "0";
        }
        else if (sum == 2) {
            res[ri] = '0';
            res += "1";
        }

        ai--; ri++;
    }

    while (bi >= 0) {
        int sum = (int)(b[bi])-48 + (int)(res[ri])-48;
        if (sum == 0) {
            res += "0";
        } 
        else if (sum == 1) {
            res[ri] ='1';
            res += "0";
        }
        else if (sum == 2) {
            res[ri] = '0';
            res += "1";
        }

        bi--; ri++;
    }

    if (res[ri] == '0') res.pop_back();

    string res_rev;
    for (int i = res.size()-1; i >= 0; i--) res_rev += res[i];
    return res_rev;
}

int main () {
    cout << addBinary("100", "110010") << endl;

}

