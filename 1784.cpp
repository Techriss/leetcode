#include <iostream>
using namespace std;

// // does not work
// bool checkOnesSegment(string s) {
//     int segments = 0;
//     for (int i = 1; i < s.size(); i++) {
//         while (i < s.size() && (s[i] == '0' || s[i] != s[i-1])) ++i;
//         if (i < s.size()) segments++;
//     }

//     return segments <= 1;
// }

bool checkOnesSegment(string s) {
    return s.find("01") == string::npos;
}



int main() {
    cout << checkOnesSegment("00110110");
}