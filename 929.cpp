#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> se;
    for (auto e : emails) {
        string s = ""; bool plused = false, atted = false;
        for (auto c : e) {
            if (c == '@') { plused = false; atted = true; }
            else if (plused) continue;
            if (c == '.' && !atted) continue;
            if (c == '+' && !atted) { plused = true; continue; }
            s += c;
        }
        se.insert(s);
    }

    return se.size();
}


// or use substr
int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> st;
    for (string &email : emails) {
        string cleanEmail;
        for (char &c : email) {
            if(c == '+' || c == '@') break;
            if(c == '.') continue;
            cleanEmail += c;
        }
        cleanEmail += email.substr(email.find('@'));
        st.insert(cleanEmail);
    }
    return st.size();
}