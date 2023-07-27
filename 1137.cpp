#include <iostream>
using namespace std;

int tribonacci(int n) {
    if (n == 0) return 0;
    else if (n == 1 || n == 2) return 1;
    
    int t0 = 0, t1 = 1, t2 = 1;
    for (int i = 2; i < n; i++) {
        t0 = t0 + t1 + t2;
        swap(t0, t1);
        swap(t1, t2);
    }

    return t2;
}


int main() {
    for (int i = 0; i < 26; i++) {
        cout << tribonacci(i) << endl;
    }
}