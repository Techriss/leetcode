#include <iostream>
#include <vector>
using namespace std;

char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    char maxc = keysPressed[0];
    int maxd = releaseTimes[0];

    for (int i = 1; i < releaseTimes.size(); i++) {
        int d = releaseTimes[i] - releaseTimes[i-1];
        if (d > maxd || (d == maxd && maxc < keysPressed[i])) {
            maxd = d;
            maxc = keysPressed[i];
        }
    }

    return maxc;
}