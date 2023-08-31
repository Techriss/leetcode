#include <iostream>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> r(9, vector<bool>(9, false));
    vector<vector<bool>> c(9, vector<bool>(9, false));
    vector<vector<vector<bool>>> s(3, vector<vector<bool>>(3, vector<bool>(9, false)));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            auto ch = board[i][j]-'1';

            if (r[i][ch] || c[j][ch] || s[i/3][j/3][ch]) return false;
            r[i][ch] = c[j][ch] = s[i/3][j/3][ch] = true;
        }
    }

    return true;
}

// or using this index trick
bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> r(9, vector<bool>(9, false));
    vector<vector<bool>> c(9, vector<bool>(9, false));
    vector<vector<bool>> s(9, vector<bool>(9, false));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            auto ch = board[i][j]-'1';
            int k = i / 3 * 3 + j / 3;

            if (r[i][ch] || c[j][ch] || s[k][ch]) return false;
            r[i][ch] = c[j][ch] = s[k][ch] = true;
        }
    }

    return true;
}

// or arrays
bool isValidSudoku(vector<vector<char>>& board) {
    short r[9][9] = {0}, c[9][9] = {0}, s[3][3][9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            auto ch = board[i][j]-'1';

            if (r[i][ch]++ || c[j][ch]++ || s[i/3][j/3][ch]++) return false;
        }
    }

    return true;
}