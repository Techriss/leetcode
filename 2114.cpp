#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// iss
int mostWordsFound(vector<string>& sentences) {
    int maxw = 0;
    string x;

    for (auto &s : sentences) {
        istringstream iss(s);
        int c = 0;

        while (iss >> x) ++c;
        maxw = max(maxw, c);
    }

    return maxw;
}


// or count spaces ...