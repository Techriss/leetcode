#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> v(n, "");
    v[0] = "1";
    if (n == 1) return v;
    v[1] = "2";
    if (n == 2) return v; 

    for (int i = 3; i <= n; i += 3) v[i-1] += "Fizz";
    for (int i = 5; i <= n; i += 5) v[i-1] += "Buzz";
    for (int i = 4; i <= n; i++) if (v[i-1].empty()) v[i-1] = to_string(i);

    return v;
}