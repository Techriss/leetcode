#include <iostream>
#include <vector>
using namespace std;

int minDeletionSize(vector<string>& strs) {
    int cols = 0;
    const int row = strs.size();
    const int col = strs[0].size();

    for (int i = 0; i < col; i++) {
        for (int j = 1; j < row; j++) {
            if (strs[j-1][i] > strs[j][i]) {
                cols++; break;
            }
        }
    }

    return cols;
}