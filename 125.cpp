#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    string res;
    for (auto c : s) {
        if (((int)c >= 48 && (int)c <= 57) || ((int)c >= 97 && (int)c <= 122)) res += c;
        else if ((int)c >= 65 && (int)c <= 90) res += (char)(((int)c)+32);
    }

    if (res.empty() || res.size() == 1) return true;

    const int n = res.size();
    int mid = n/2;
    string l, r;

    for (int i = 0; i < mid; i++) {
        if (res[i] != res[n-i-1]) return false;
    }

    return true;
}

int main() {
    cout << isPalindrome("A man, a plan, a canal: Panama");
}