#include <iostream>
#include <vector>
using namespace std;

// simulate
int getMaximumGenerated(int n) {
    if (n == 0) return 0;

    vector<int> v(n+1, 0);
    v[0] = 0;
    v[1] = 1;

    int maxv = 1;

    for (int i = 2; i <= n; i++) {
        v[i] = i % 2 ? v[i/2] + v[i/2+1] : v[i/2];
        maxv = max(v[i], maxv);
    }
    return maxv;
}

// even first
int getMaximumGenerated(int n) {
    if (n == 0) return 0;

    vector<int> v(n+1, 0);
    v[0] = 0;
    v[1] = 1;

    int maxv = 0;

    for (int i = 1; i <= n; i++) {
        if (v[i] != 0 && i != 1) continue;

        v[i] = v[i/2] + v[i/2+1];
        for (int j = i; j <= n; j *= 2) v[j] = v[i];
        maxv = max(v[2*i+1], maxv);
    }

    return maxv;
}


int main() {
    getMaximumGenerated(16);
}


/*

 0: 0
 1: 1
 2: 1
 3: 2
 4: 1
 5: 3
 6: 2
 7: 3
 8: 1
 9: 4
10: 3
11: 
12: 2
13:
14: 3
15: 
16: 1


*/