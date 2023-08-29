#include <iostream>
using namespace std;

// subtract divisor by divisor (too slow) [TLE]
int divide(int dividend, int divisor) {
    unsigned long long res = 0;
    bool neg = (dividend < 0) ^ (divisor < 0);
    dividend = abs(dividend), divisor = abs(divisor);

    for (unsigned long long i = divisor; i <= dividend; i += divisor) {
        ++res;
        if ((!neg && res == 2147483647) || res == 2147483648) break;
    }
    return neg ? -res : res;
}



// we'll try to fit in most multiples of divisor
// not by multiplying itself, but by leftshifting by 1 (so multiplying by 2)
int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    const int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

    while (dvd >= dvs) {

        // temp is the multiple, m is for m*divisor = temp
        long temp = dvs, m = 1;

        // while tmp*2 <= divident, tmp *= 2;
        while (temp << 1 <= dvd) {
            temp <<= 1;
            m <<= 1;
        }

        dvd -= temp;
        ans += m;
    }


    return sign * ans;
}


// or some fancy maths
// but it prolly isnt what the problems about
int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    if (divisor == 0) return INT_MAX;
    long long res = double(exp(log(fabs(dividend))-log(fabs(divisor))));
    if ((dividend < 0)^(divisor < 0)) res =- res;
    if (res > INT_MAX) res = INT_MAX;
    return res;
}
