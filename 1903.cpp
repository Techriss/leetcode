#include <iostream>
using namespace std;

// hyp: last odd num from first non-zero
// res: thats right

// char by char
string largestOddNumber(string num) {
    string n = "", part = "";
    int l = 0;
    while (num[l] == '0') ++l;

    for (int i = l; i < num.size(); i++) {
        part += num[i];
        if (num[i] % 2) n += part, part = "";
    }

    return n;
}

// indices
string largestOddNumber(string num) {
    int l = 0;

    // omit leading zeros
    while (num[l] == '0') ++l;

    // look for last odd number (first odd from right)
    for (int i = num.size()-1; i >= l; i--) {
        if (num[i] % 2) return num.substr(l, i-l+1);
    }

    return "";
}

// without accouting for leading zeros
string largestOddNumber(string num) {
    for (int i = num.size()-1; i >= 0; i--) {
        if (num[i] % 2) return num.substr(0, i+1);
    }

    return "";
}


// one liner
string largestOddNumber(string n) {
    return n.substr(0, n.find_last_of("13579") + 1);
}