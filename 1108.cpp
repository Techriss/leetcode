#include <iostream>
#include <regex>
using namespace std;

// copy
string defangIPaddr(string address) {
    string s;
    for (auto &c : address) {
        if (c == '.') s += '[';
        s += c;
        if (c == '.') s += ']';
    } 

    return s;
}

// regex
string defangIPaddr(string a) {
    return regex_replace(a, regex("\\."), "[.]");
}

// insert
string defangIPaddr(string address) {
    for (int i = 0; i < address.length(); i++){
        if (address[i] == '.'){
            address.insert(address.begin() + (i), '[');
            i++;
            address.insert(address.begin() + (i + 1), ']');
        }
    }

    return address;
}