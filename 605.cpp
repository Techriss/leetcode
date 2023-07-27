#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    for (int i = 0; i < flowerbed.size() && n > 0; i++) {
        if (!flowerbed[i]) {
            bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
            bool emptyRightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);

            if (emptyLeftPlot && emptyRightPlot) {
                flowerbed[i] = 1;
                n--;
            }
        }
    }

    return n <= 0;
}