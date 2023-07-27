#include <iostream>
using namespace std;

bool checkRecord(string s) {
    int ls = 0, as = 0;
    for (auto c : s) {
        if (c == 'A' && ++as == 2) return false;
        else if (c == 'L' && ++ls == 3) return false;
        else if (c != 'L') ls = 0;
    }
    return true;
}

int main() {
    cout << checkRecord("PPALLL") << endl;
}