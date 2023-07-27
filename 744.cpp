#include <iostream>
#include <vector>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    char cmin = '{';
    for (auto c : letters) {
        if (c > target && c < cmin) cmin = c;
    }

    return cmin == '{' ? letters[0] : cmin;
}	


int main() {
    vector<char> v({'c', 'f', 'a'});
    cout << nextGreatestLetter(v, 'c') << endl;
}