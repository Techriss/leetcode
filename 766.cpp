#include <iostream>
#include <vector>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    // top to bottom diagonals
    for (int i = 0; i < matrix[0].size()-1; i++) {
        cout << "i: " << i << endl;
        for (int j = 0, k = i; j < matrix.size()-1 && k < matrix[0].size()-1; j++, k++) {
            if (matrix[j][k] != matrix[j+1][k+1]) return false;
        }
    }

    // left diagonals (not touching top)
    for (int i = 1; i < matrix.size()-1; i++) {
        for (int j = i, k = 0; j < matrix.size()-1 && k < matrix[0].size()-1; j++, k++) {
            if (matrix[j][k] != matrix[j+1][k+1]) return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> v({
        {11, 74, 0, 93},
        {40, 11, 74, 7}
    });
    cout << isToeplitzMatrix(v) << endl;
}