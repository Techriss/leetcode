#include <iostream>
using namespace std;

int titleToNumber(string columnTitle) {
    int n = 0;
    long long mult = 1;

    while (!columnTitle.empty()) {
        if (columnTitle[columnTitle.size()-1] == 'Z') n += 26*mult;
        else n += (((int)(columnTitle[columnTitle.size()-1]))-64)*mult;

        columnTitle = columnTitle.substr(0, columnTitle.size()-1);
        mult *= 26;
    }

    return n;
}

int titleToNumber_2(string columnTitle) {
    int n = 0;
    for (auto c : columnTitle) {
        n = (n*26) + (c-'A'+1);
    }
    return n;
}

int main() {
    cout << titleToNumber("A") << endl;
    cout << titleToNumber("Z") << endl;
    cout << titleToNumber("AA") << endl;
    cout << titleToNumber("AZ") << endl;
    cout << titleToNumber("BA") << endl;
    cout << titleToNumber("ZY") << endl;
}