#include <iostream>
using namespace std;

string reformat(string s) {
    string ds = "", ls = "";
    for (auto &c : s) {
        if (c >= 'a' && c <= 'z') ls += c;
        else ds += c;
    }

    s = "";

    const int diff = (int)ds.size() - (int)ls.size();
    const int minsize = min(ds.size(), ls.size());
    if (abs(diff) > 1) return "";
    const int flag = (diff == 0) ? 0 : ((diff > 0) ? 1 : -1);

    int i = 0;
    for (i = 0; i < minsize; i++) {
        if (flag >= 0) { s += ds[i]; s += ls[i]; }
        else { s += ls[i]; s += ds[i]; }
    }

    if (flag == 1) s += ds[i];
    else if (flag == -1) s += ls[i];

    return s;
}

int main() {
    cout << reformat("abc123") << endl;
}