#include <string>
#include <iostream>
#include <vector>
using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++){
        if (strs[i].empty()) return "";
        for (int j = 0; j < strs[i].size() && j < prefix.size(); j++) {
            if (prefix[j] != strs[i][j] || (j == strs[i].size()-1 && j++ < prefix.size())) {
                prefix = prefix.substr(0, j);
                break;
            }
        }
    }
    return prefix;
}

int main() {
    vector<string> v({"ab", "a"});
    cout << longestCommonPrefix(v) << endl;
}