#include <iostream>
#include <regex>
using namespace std;

// iterative, 4 last chars handled with every case
string reformatNumber(string number) {
    string s = "", s2 = "";
    for (auto &c : number) {
        if (c != ' ' && c != '-') s += c;
    }


    int d = s.size();
    for (int i = 0; i+4 < d; i += 3) {
        s2 += s[i];
        s2 += s[i+1];
        s2 += s[i+2];
        s2 += '-';
    }


    if (d % 3 == 1) {
        s2 += s[d-4];
        s2 += s[d-3];
        s2 += '-'; 
        s2 += s[d-2]; 
        s2 += s[d-1];
    }
    else if (d % 3 == 2) {
        s2 += s[d-2]; 
        s2 += s[d-1];
    }
    else {
        s2 += s[d-3];
        s2 += s[d-2];
        s2 += s[d-1];
    }


    return s2;
}

// good luck
string reformatNumber(string number) {
    return regex_replace(regex_replace(number, regex("\\D"), ""), regex("...?(?=..)"), "$0-");
}



int main() {
    cout << reformatNumber("123 4-567896");
}