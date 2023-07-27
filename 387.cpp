#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> m;
    vector<char> insertion_order;

    for (int i = 0; i < s.size(); i++) {
        if (m.find(s[i]) == m.end())  {
            m[s[i]] = i;
            insertion_order.push_back(s[i]);
        }
        else m[s[i]] = -1;
    }

    for (auto c : insertion_order) {
        if (m[c] != -1) return m[c];
    }

    return -1;
}

int firstUniqChar(string s) {
    unordered_map<char, int> m;
    queue<char> q;

    for (int i = 0; i < s.size(); i++) {
        if (m.find(s[i]) == m.end())  {
            m[s[i]] = i;
            q.push(s[i]);
        }
        else {
            m[s[i]] = -1;
            if (q.front() == s[i]) q.pop();
        }
    }

    while (!q.empty()) {
        if (m[q.front()] != -1) return m[q.front()];
        else q.pop();
    }

    return -1;
}

int main() {
    cout << firstUniqChar("leetcode") << endl;
}