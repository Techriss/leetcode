#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    if (s.size() == 1 && s[0] != ' ') return 1;
    int i = s.size() - 1;

    while (s[i] == ' ' && i > 0) i--;
    if (i < 0) return 0;

    int start = i;
    if (start == 0 && s[start] != ' ') return 1;
    while (s[i] != ' ' && i > 0) i--;
    if (i == 0 && s[i] != ' ') i--;

    return start - i;
}

int main() {
    cout << lengthOfLastWord(" ssss") << endl;

}