#include <iostream>
#include <set>
using namespace std;

// just look for 2 max
int secondHighest(string s) {
    int d1 = -1, d2 = -2;
    for (auto &c : s) {
        if (c >= '0' && c <= '9') {
            int d = c-48;
            if (d > d1) d2 = d1, d1 = d;
            else if (d < d1 && d > d2) d2 = d; 
        }
    }

    return max(d2, -1);
}

// ordered set
int secondHighest(string s) {
    set<int> st;
    
    for(const char &c : s) {
        if (isdigit(c))
            st.insert(c-'0');
    }
    
    // either -1 or last element of set (since it's ordered)
    return st.size() > 1 ? *next(rbegin(st)): -1;
}
