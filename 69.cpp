#include <iostream>
using namespace std;

int mySqrt(int x) {
      if (x == 0) return 0;
      if (x == 1 || x == 2 || x == 3) return 1;

      int l = 1, r = x/2;
      long long mid;
      while (l <= r) {
        mid = (l+r)/2;
        if (mid*mid == x) return mid;
        else if (mid*mid < x) l = mid + 1;
        else r = mid -1;
      }

      while (mid*mid > x) mid--;
      while (mid*mid < x) mid++;
      mid--;
      return mid;
}


int main() {
    int x;
    while (cin >> x) {
        cout << mySqrt(x) << endl;
    }
}


/**
 * 
 * 
 * 
 * 
 * 536848900
 * 2147395599
*/