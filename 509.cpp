#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0) return 0;
    
    int f1 = 0, f2 = 1;
    while (n --> 1) {
        f1 = f1+f2;
        swap(f1, f2);
    }

    return f2;
}

int main() {
    for (int i = 0; i <= 30; i++) cout << fib(i) << endl;
}