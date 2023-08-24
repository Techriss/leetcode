#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// since the number of seats and students is the same,
// sorting the arrays will give every student its nearest seat
int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    int moves = 0;
    sort(students.begin(), students.end());
    sort(seats.begin(), seats.end());

    for (int i = 0; i < students.size(); i++)
        moves += abs(students[i] - seats[i]);
    
    return moves;
}


// counting sort
int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    int moves = 0;
    const int n = seats.size();

    vector<int> v1(101, 0);
    vector<int> v2(101, 0);

    for (auto &s : seats) ++v1[s];
    for (auto &s : students) ++v2[s];

    for (int i = 1, j = 1, k = 0; k < n; ) {
        if (v1[i] == 0) ++i;
        else if (v2[j] == 0) ++j;
        else {
            moves += abs(i - j);
            ++k;
            --v1[i];
            --v2[j];
        }
    }

    return moves;
}


int main() {
    vector<int> v1({2, 2, 6, 6});
    vector<int> v2({1, 3, 2, 6});
    cout << minMovesToSeat(v1, v2);
}