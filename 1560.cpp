#include <iostream>
#include <vector>
using namespace std;

// count
vector<int> mostVisited(int n, vector<int>& rounds) {
    vector<int> sectors(n+2, 0);

    // counting
    for (int i = 1; i < rounds.size(); i++) {
        for (int j = rounds[i-1]; j != rounds[i]; j = (j%n)+1) sectors[j]++;
    }

    sectors[rounds[rounds.size()-1]]++;


    // getting max
    vector<int> v({1});
    int maxv = sectors[1];

    for (int i = 2; i <= n; i++) {
        if (sectors[i] > maxv) {
            maxv = sectors[i];
            v.clear();
            v.push_back(i);
        }
        else if (sectors[i] == maxv) v.push_back(i);
    }

    return v;
}


// but: we only need to care about start and end of all rounds
vector<int> mostVisited(int n, vector<int>& A) {
    vector<int> res;

    // is first before last, return range between
    for (int i = A[0]; i <= A[A.size() - 1]; ++i)
        res.push_back(i);
    if (res.size() > 0) return res;

    // otherwise return 1-last and first-n 
    for (int i = 1; i <= A[A.size() - 1]; ++i)
        res.push_back(i);
    for (int i = A[0]; i <= n; ++i)
        res.push_back(i);

    return res;
}

int main() {
    vector<int> v({1, 3, 1, 2});
    mostVisited(4, v);
}

/*

1: 
2: 
3: 
4: 


*/