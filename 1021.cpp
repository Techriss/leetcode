#include <iostream>
#include <stack>
using namespace std;

// with stack
string removeOuterParentheses(string s) {
    stack<char> st;
    string s2 = "";

    for (int i = 0; i < s.size(); i++) {
        if (st.empty()) st.push(s[i]);
        else {
            if (s[i] == '(') { st.push(s[i]); s2 += '('; }
            else if (st.size() > 1) { st.pop(); s2 += ')'; }
            else st.pop();
        }
    }

    return s2;
}

// with counter
string removeOuterParentheses(string S) {
    string res;
    int opened = 0;
    for (char &c : S) {
        if (c == '(' && opened++ > 0) res += c;
        if (c == ')' && opened-- > 1) res += c;
    }
    return res;
}