#include <iostream>
using namespace std;

// simulation
int totalMoney(int n) {
    int week = 1;
    int money = 1;


    for (int i = 1; i < n; i++) {
        if (i%7 == 0) ++week;
        money += i%7;
        money += week;
    }

    return money;
}

/*
(n+1)n/2 = 1 + ... + n
(7+1)7/2 = 1 + ... + 7
            w + 1 + ... + w + 7 = (1 + ... + 7) + 7(w-1) = (7+1)7/2 + 7(w-1) = (8+2(w-1))7/2 = (w+3)7 


sum of arith. seq = (n/2)*(a1+an)
where n = full weeks in this case

n/7/2 * ((1+3)*7 + (n/7 + 3)*7) = n/7/2 * 7(7 + n/7) = (49 + n)(n / 14)

and leftover
(f + 1 + (f + 1 + d - 1)) * d / 2 = (2 * f + d + 1) * d / 2

*/

// math
int totalMoney(int n) {
    int f = n/7;
    int d = n%7;

    return (49 + 7*f)*f/2 + (2*f + d+1)*d/2;
}