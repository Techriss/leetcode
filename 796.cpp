#include <iostream>
using namespace std;


// every combination, without using substr
bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;

    for (int i = 0; i < s.size(); i++) {
        bool ok = true;
        for (int j = i; j < s.size(); j++) if (goal[j-i] != s[j]) { ok = false; break; }
        if (!ok) continue;
        for (int j = 0; j < i; j++) if (goal[j+(goal.size()-i)] != s[j]) { ok = false; break; }
        if (!ok) continue;
        return true;
    }
    return false;
}

// simpler
bool rotateString(string s, string goal) {
    return (s.size() == goal.size() && (s+s).find(goal) != string::npos);
}

// for example
/*

    s:   abcde
    g:   cdeab
    s+s: abcdeabcde
           ^^^^^ --> and here's our goal

*/

int main() { 
    rotateString("abcde", "cdeab");
}