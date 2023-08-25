#include <iostream>
#include <vector>
using namespace std;

// using bits
int countPoints(string rings) {
    int res = 0;
    vector<int> v(10, 0);
    for (int i = 0; i < rings.size(); i += 2) {
        if (rings[i] == 'R') v[rings[i+1]-'0'] |= 1;
        else if (rings[i] == 'G') v[rings[i+1]-'0'] |= 2;
        else v[rings[i+1]-'0'] |= 4;
    }

    for (int i = 0; i < 10; i++) res += v[i] == 7;
    return res;
}