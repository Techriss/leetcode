#include <iostream>
using namespace std;

// special cases
int minimumMoves(string s) {
    int moves = 0, i;
    const int n = s.size();

    for (i = 2; i < n; i++) {
        if (s[i-2] == 'X') ++moves, i += 2;
    }

    if (i == n+2) return moves;
    if (i == n+1) moves += (s[i-2] == 'X');
    if (i == n) moves += ((s[i-2] == 'X') || (s[i-1] == 'X'));
    return moves;
}

// easier
// we do we have to have a physical 3? we can simply imagine it having the first element (last 2 may or may not exist)
int minimumMoves(string s) {
    int moves = 0, i;
    const int n = s.size();

    for (i = 0; i < n; i++) {
        if (s[i] == 'X') ++moves, i += 2;
    }

    return moves;
}
