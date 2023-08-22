#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int numDifferentIntegers(string word) {
    string n = "";
    unordered_set<string> s;

    for (auto &c : word) {
        if (isdigit(c)) {
            // if curr number contains leading zeros, get rid of them one by one
            while (!n.empty() && n[0] == '0') n = n.substr(1);
            n += c;
        }
        else if (!n.empty()) { s.insert(n); n = ""; }
    }

    if (!n.empty()) s.insert(n);
    return s.size();
}


// twi pointers
int numDifferentIntegers(string w) {
    unordered_set<string> s{""};    
    for (int i = 0, j = 0; j <= w.size(); ++j) {

        // search for digit with j
        if (j < w.size() && isdigit(w[j]))

            // if j is digit, j is after i and i is a leading zero, increment i
            i += i < j && w[i] == '0';
        else {

            // either end or number ended, insert whole number and move i
            s.insert(w.substr(i, j - i));
            i = j + 1;
        }
    }
    return s.size() - 1;
}