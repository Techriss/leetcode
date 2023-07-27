#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    int mid = s.size()/2;
    for (int i = 0; i < mid; i++) {
        swap(s[i], s[s.size()-i-1]);
    }
}

int main() {
    vector<char> s({'h', 'e', 'l', 'l', 'o'});
    reverseString(s);
    for (auto c : s) cout << c;

}