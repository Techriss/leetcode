#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int numRookCaptures(vector<vector<char>>& board) {
    vector<pair<int, int>> ps;      // pawns
    vector<pair<int, int>> bs;      // bishups
    pair<int, int> r = {-1, -1};    // rook
    int count = 0;
    bool lp = false, rp = false, tp = false, bp = false; // whether there has been any pawn counted here already

    // add all with optimization
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == 'R') r = {i, j};
            else if (board[i][j] == 'p') { if (r.first == -1 || i == r.first || j == r.second) ps.push_back({i, j}); }
            else if (board[i][j] == 'B') { if (r.first == -1 || i == r.first || j == r.second) bs.push_back({i, j}); }
        }
    }

    for (auto &p : ps) {
        if ((p.first == r.first || p.second == r.second)) {
            // if already here
            if (p.first == r.first && p.second > r.second && rp) continue;
            else if (p.first == r.first && p.second < r.second && lp) continue;
            else if (p.second == r.second && p.first < r.first && tp) continue;
            else if (p.second == r.second && p.first > r.first && bp) continue;

            // for all bishups
            bool skip = false;
            for (auto &b : bs) {
                if (p.first == r.first && p.first == b.first && p.second > r.second && b.second < p.second && b.second > r.second) { skip = true; break; }
                if (p.first == r.first && p.first == b.first && p.second < r.second && b.second > p.second && b.second < r.second) { skip = true; break; }
                if (p.second == r.second && p.second == b.second && p.first > r.first && b.first < p.first && b.first > r.first) { skip = true; break; }
                if (p.second == r.second && p.second == b.second && p.first < r.first && b.first > p.first && b.first < r.first) { skip = true; break; }
            }

            // got a pawn
            if (!skip) {
                count++;
                if (p.first == r.first && p.second > r.second) rp = true;
                else if (p.first == r.first && p.second < r.second) lp = true;
                else if (p.second == r.second && p.first < r.first) tp = true;
                else if (p.second == r.second && p.first > r.first) bp = true;
            }
        }
    }

    return count;
}


int main() {
    vector<vector<char>> v({
        vector<char>({'.','.','.','.','.','.','.','.'}),
        vector<char>({'.','.','.','p','.','.','.','.'}),
        vector<char>({'.','.','.','p','.','.','.','.'}),
        vector<char>({'p','p','.','R','.','p','B','.'}),
        vector<char>({'.','.','.','.','.','.','.','.'}),
        vector<char>({'.','.','.','B','.','.','.','.'}),
        vector<char>({'.','.','.','p','.','.','.','.'}),
        vector<char>({'.','.','.','.','.','.','.','.'})
        });

    cout << numRookCaptures(v) << endl;
}