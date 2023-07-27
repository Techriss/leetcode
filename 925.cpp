#include <iostream>
using namespace std;

bool isLongPressedName(string name, string typed) {
    if (name[0] != typed[0]) return false;
    char prev = name[0];
    int count = 1, i, j;

    for (i = 1, j = 0; i <= name.size() && j < typed.size(); i++) {
        while (i < name.size() && prev == name[i]) { count++; i++; }             // count char occurs
        while (j < typed.size() && count > 0 && typed[j] == prev) { count--; j++; }      // pop proper occurs
        if (j < typed.size() && count > 0 && typed[j] != prev) return false;      // false if not enough occurs in typed
        while (j < typed.size() && typed[j] == prev) j++;       // pop redundant occurs

        prev = name[i];
        count = 1;
    }

    return j == typed.size() && i == name.size()+1;
}

int main() {
    cout << isLongPressedName("alex", "aaleex") << endl;
}