#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// pushing brackets at every i, j combination
// too slow (beats 6%)
vector<string> generateParenthesis(int n) {
    vector<string> v({"()"});

    for (int i = 1; i < n; i++) {
        unordered_set<string> news;
        for (auto &p : v) {
            const int pn = p.size();
            for (int j = 0; j < pn; j++)
                for (int k = j; k < pn; k++) {
                    string p2 = p;
                    p2.insert(p2.begin() + j, '(');
                    p2.insert(p2.begin() + k + 1, ')');
                    news.insert(p2);
                }
                    
                    
        }

        v.clear();
        for (auto &p : news)
            v.push_back(p);
    }

    return v;
}



// way faster
/*

    think of a string as n*2 places _ _ _ _
    where in each place we can put either ( or )
    but that changes depending on whether we opened enough to close, or have enough space to open more

    so by keeping track of opened and closed brackets, we can create a recursion tree
*/

vector<string> generateParenthesis(int n) {
    vector<string> v;
    rec(v, "", 0, 0, n);
    return v;
}


/*
    for every call
    we make 2 choices:
        either open a new bracket
        or close one
    
    we push the result only if it reaches the target length

*/
void rec(vector<string> &v, string s, int open, int close, int n) {
    // open == close == n
    if (s.length() == 2*n) {
        v.push_back(s);
        return;
    }

    // if can open another bracket, do it
    if (open < n) rec(v, s + '(', open + 1, close, n);

    // if there's something waiting to be closed, consider that option
    if (close < open) rec(v, s + ')', open, close + 1, n);
}


/*

                        (0, 0, '')
                            |	
                        (1, 0, '(')  
                        /           \
                (2, 0, '((')      (1, 1, '()')
                    /                 \
            (2, 1, '(()')           (2, 1, '()(')
                /                       \
        (2, 2, '(())')                (2, 2, '()()')
                    |	                             |
        res.append('(())')             res.append('()()')

*/




// slightly different
vector<string> generateParenthesis(int n) {
    vector<string> res;
    addingpar(res, "", n, 0);
    return res;
}

/*
    n is to be opened
    m is to be closed

*/
void addingpar(vector<string> &v, string str, int n, int m) {
    if (n == 0 && m == 0) {
        v.push_back(str);
        return;
    }

    // if something's waiting to be closed, close it
    if (m > 0) addingpar(v, str + ")", n, m-1);

    // if you can open, open
    if (n > 0) addingpar(v, str + "(", n-1, m+1);
}