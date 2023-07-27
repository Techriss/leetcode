#include <iostream>
using namespace std;

int maxScore(string s) {
    int score = 0, maxscore = 0;
    for (auto &c : s) if (c == '1') ++score;

    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] == '1') --score;
        else ++score;

        maxscore = max(score, maxscore);
    }

    return maxscore;
}

int main() {
    cout << maxScore("0101") << endl;
}