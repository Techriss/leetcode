#include <iostream>
using namespace std;

int countSegments(string s) {
    if (s.empty()) return 0;

    int i = 0;
    while (s[i] == ' ') i++;

    int segments = 0;
    bool space = false;

    while (i < s.size()) {
        while (s[i] != ' ' && i < s.size()) i++;
        segments++;
        while (s[i] == ' ' && i < s.size()) i++;
    }

    return segments;
}


int main() {
    cout << countSegments("x ") << endl;

}