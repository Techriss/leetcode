#include <iostream>
#include <queue>
using namespace std;

bool isSubsequence(string s, string t) {
    queue<char> q;
    for (auto c : s) q.push(c);
    for (auto c : t) {
        if (c == q.front()) q.pop();
    }

    return q.empty();
}  