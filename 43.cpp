#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

/*
    for string multiplication, we need to perform manual multiplication (like on paper)
    and add the subresults together at the right places

    here, we can combine those two parts of the process:
        we can multiply every pair and put it in the array at the right places
        we can simultaneously add digits of previously computed products to the current product and its carry
        
*/
string multiply(string num1, string num2) {
    const int n = num1.size(), m = num2.size();
    string sum(n + m, '0');
    
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
            sum[i + j + 1] = tmp % 10 + '0';
            sum[i + j] += tmp / 10;
        }
    }
    
    auto startpos = sum.find_first_not_of("0");
    return startpos == string::npos ? "0" : sum.substr(startpos);
}





































// trying but failed here (none of this works for big numbers)
string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while(i>=0 || j>=0 || carry){
        long sum = 0;
        if(i >= 0){sum += (num1[i] - '0');i--;}
        if(j >= 0){sum += (num2[j] - '0');j--;}
        sum += carry; 
        carry = sum / 10;
        sum = sum % 10;
        res =  res + to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
}

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    if (num1.size() < num2.size()) swap(num1, num2);
    int l = 0;
    string total = "0";

    for (int i = num2.size() - 1; i >= 0; i--) {
        int x = num2[i]-'0', carry = 0, l2 = 0;
        string sum = "0";

        for (int j = num1.size()-1; j >= 0; j--) {
            int y = num1[j]-'0';
            sum = addStrings(sum, to_string((unsigned long long)pow(10, l2) * (((x * y) + carry) % 10)));
            carry = ((x * y) + carry) / 10;
            ++l2;
        }

        if (carry) sum = addStrings(sum, to_string((unsigned long long)pow(10, l2) * carry));

        for (int k = 0; k < l; k++) sum += '0';
        total = addStrings(sum, total);
        ++l;
    }

    return total;
}

int main() {
    cout << multiply("925101087184894", "3896737933784656127") << endl;
}


/*

     1
    123
    456
------------------
    738
   615
  492

  56088



  123
   12

*/