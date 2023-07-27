#include <iostream>
using namespace std;

int binaryGap(int n) {
    int i = -1, j = 0, maxd = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            if (i != -1) maxd = max(maxd, j-i);
            i = j;
        }

        j++;
        n /= 2;
    }
    
    return maxd;
}