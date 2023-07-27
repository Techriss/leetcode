#include <iostream>
using namespace std;

bool judgeCircle(string moves) {
    long long v = 0, h = 0;
    for (auto c : moves) {
        if (c == 'U') v++;
        else if (c == 'D') v--;
        else if (c == 'L') h--;
        else h++;
    }

    return v == 0 && h == 0;
}