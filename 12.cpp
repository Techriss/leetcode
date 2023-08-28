#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string intToRoman(int num) {
    string s = "";
    vector<char> v({'I', 'V', 'X', 'L', 'C', 'D', 'M'});

    for (int c = 0; num > 0; c += 2, num /= 10) {
        int rem = num % 10;

        if (rem <= 3)
            for (int i = 0; i < rem; i++) s += v[c];

        else if (rem == 4)
            s += v[c+1], s += v[c];

        else if (rem == 5)
            s += v[c+1];

        else if (rem >= 6 && rem <= 8) {
            for (int i = 5; i < rem; i++) s += v[c];
            s += v[c+1];
        }

        else
            s += v[c+2], s += v[c];
    }

    reverse(s.begin(), s.end());
    return s;
}


// or be rude
string intToRoman(int num) {
    string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string ths[]={"","M","MM","MMM"};
    
    return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
}