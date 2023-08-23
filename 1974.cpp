#include <iostream>
using namespace std;

int minTimeToType(string word) {
    int s = word.size();
    int prev = 'a';

    for (auto &c : word) {
        int dist = abs(c-prev);
        s += min(dist, 26-dist);
        prev = c;
    }

    return s;
}
