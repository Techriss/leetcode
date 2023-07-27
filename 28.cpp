#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    for (int i = 0; i + needle.size() <= haystack.size(); i++) {
        if (haystack[i] == needle[0] && haystack.substr(i, needle.size()) == needle) {
            return i;
        }
    }
    return -1;
}


int main() {
    cout << strStr("hello", "ll") << endl;

}