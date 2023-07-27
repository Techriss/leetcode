#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> closing {{'{', '}'}, {'(', ')'}, {'[', ']'}};
    for (auto c : s) {
        if (c == '{' || c == '(' || c == '[') {
            st.push(c);
        }
        else {
            if (c == closing[st.top()]) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}