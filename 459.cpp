#include <iostream>
using namespace std;

bool repeatedSubstringPattern(string s) {
    const int n = s.size();
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            bool flag = true;
            for (int j = i; j < n; j += i) {
                if (s.substr(j, i) != s.substr(0, i)) {
                    flag = false;
                    break;
                }
            }

            if (flag) return true;
        }
    }

    return false;
}

int main() {
    cout << repeatedSubstringPattern("abcabc") << endl;
}