#include <iostream>
using namespace std;

string gcdOfStrings(string str1, string str2) {
    const int n = str1.size(), m = str2.size();

    for (int i = str2.size(); i > 0; i--) {
        if (n % i != 0 || m % i != 0) continue;
        bool skip = false;
        string d = str2.substr(0, i);

        for (int i = 0; i < n || i < m; i += d.size()) { 
            if (i < n && str1.substr(i, d.size()) != d) { skip = true; break; }
            if (i < m && str2.substr(i, d.size()) != d) { skip = true; break; }
        }

        if (!skip) return d;
    }

    return "";
}


string gcdOfStrings(string str1, string str2) {
    return (str1 + str2 == str2 + str1) ? str1.substr(0, __gcd(size(str1), size(str2))): "";
}
