#include <iostream>
using namespace std;

string toGoatLatin(string sentence) {
    string res = "", w = "";
    int count = 1;

    sentence += ' ';

    for (auto c : sentence) {
        if (c != ' ') w += c;
        else if (w != "") {
            if (tolower(w[0]) == 'a' || tolower(w[0]) == 'e' || tolower(w[0]) == 'i' || tolower(w[0]) == 'o' || tolower(w[0]) == 'u') w += "ma";
            else w = w.substr(1, w.size()) + w[0] + "ma";
            for (int i = 0; i < count; i++) w += 'a';
            res += w;
            res += ' ';
            w = "";
            count++;
        }
    }

    res.pop_back();
    return res;
}