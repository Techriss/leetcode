#include <iostream>
#include <vector>
using namespace std;

string restoreString(string s, vector<int>& indices) {
    string res(s.size(), ' ');
    for (int i = 0; i < s.size(); i++) res[indices[i]] = s[i];
    return res; 
}

string restoreString(string s, vector<int>& indices) {
    for (int i = 0; i != indices.size(); ) {
        if (indices[i] == i) i++;
        else {
            swap(s[i], s[indices[i]]);
            swap(indices[i], indices[indices[i]]);
        }
    }

    return s;
}