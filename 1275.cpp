#include <iostream>
#include <vector>
using namespace std;

// idea: for every 3 of same points, check if collinear (triangle area = 0 formula) [fast since very few cases]
// result: actually beats 100% time and memory
string tictactoe(vector<vector<int>>& moves) {
    const int n = moves.size();

    for (int i = 0; i < n; i += 2) {
        for (int j = i+2; j < n; j += 2) {
            for (int k = j+2; k < n; k += 2) {
                if (i != j && j != k && ((moves[i][0]*(moves[j][1]-moves[k][1]) + moves[j][0]*(moves[k][1]-moves[i][1]) + moves[k][0]*(moves[i][1]-moves[j][1])) == 0)) return "A";
            }
        }
    }

    for (int i = 1; i < n; i += 2) {
        for (int j = i+2; j < n; j += 2) {
            for (int k = j+2; k < n; k += 2) {
                if (i != j && j != k && ((moves[i][0]*(moves[j][1]-moves[k][1]) + moves[j][0]*(moves[k][1]-moves[i][1]) + moves[k][0]*(moves[i][1]-moves[j][1])) == 0)) return "B";
            }
        }
    }

    if (n == 9) return "Draw";
    return "Pending";
}



// another way: save in array
string tictactoe(vector<vector<int>>& moves) {
        vector<int> A(8,0), B(8,0); // 3 rows, 3 cols, 2 diagonals
        for(int i=0; i<moves.size(); i++) {
            int r=moves[i][0], c=moves[i][1];
            vector<int>& player = (i%2==0)?A:B;
            player[r]++;
            player[c+3]++; 
            if(r==c) player[6]++;
            if(r==2-c) player[7]++;
        }
        for(int i=0; i<8; i++) {
            if(A[i]==3) return "A";
            if(B[i]==3) return "B";
        }
        return moves.size()==9 ? "Draw":"Pending";
}