#include <iostream>
using namespace std;

string convertToTitle(int columnNumber) {
    string s = "";
    while (columnNumber > 0) {
        if (columnNumber % 26 == 0) s += 'Z';
        else s += (char)(((columnNumber) % 26) + 64);
        columnNumber = (columnNumber-1)/26;
    }
    

    string s2 = "";
    for (int i = s.size()-1; i >= 0; i--) s2 += s[i];
    return s2;
}

int main() {
    cout << convertToTitle(1) << endl;
    cout << convertToTitle(26) << endl;
    cout << convertToTitle(27) << endl;
    cout << convertToTitle(52) << endl;
    cout << convertToTitle(53) << endl;
    cout << convertToTitle(2345) << endl;
}