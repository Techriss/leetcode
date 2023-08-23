#include <iostream>
#include <string>
using namespace std;

// on strings
int getLucky(string s, int k) {
    string n = "";
    for (auto &c : s) n += to_string(c-96);
    int sum = 0;
    for (auto &c : n) sum += c-48;

    --k;

    while (k --> 0) {
        int newsum = 0;
        while (sum > 0) newsum += sum % 10, sum /= 10;
        sum = newsum;
    }

    return sum;
}


int main() {
    cout << getLucky("leetcode", 2);
}