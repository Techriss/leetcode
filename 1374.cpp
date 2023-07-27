#include <iostream>
using namespace std;

string generateTheString(int n) {
    string s = "";
    if (n % 2 == 0) { s = "a"; n--; }
    s.insert(s.end(), n, 'b');
    return s; 
}

// or more concise
// if rem=1, bbbbbbbbbb, else baaaaaaaaa
string generateTheString(int n) {
    return "b" + string(n - 1, 'a' + n % 2);
}