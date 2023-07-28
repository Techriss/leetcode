#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// brute
vector<int> finalPrices(vector<int>& prices) {
    for (int i = 0; i < prices.size()-1; i++) {
        for (int j = i+1; j < prices.size(); j++) {
            if (prices[j] <= prices[i]) { prices[i] -= prices[j]; break; }
        }
    }

    return prices;
}


// stack (keeping prices in the stack)
// explanation: you push every element onto the stack,
//              if the curr element is <= than s.top()
//              it is the next lesser element than top
//              so subtract it from the top (via index)
vector<int> finalPrices(vector<int>& A) {
    stack<int> s;
    for (int i = 0; i < A.size(); ++i) {
        while (!s.empty() && A[s.top()] >= A[i]) {
            A[s.top()] -= A[i];
            s.pop();
        }
        s.push(i);
    }

    return A;
}



// or stack from right to left (keeping discounts in the stack)
vector<int> finalPrices(vector<int>& prices) {
    stack<int> s;
    for (int i = prices.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() > prices[i]) s.pop(); // we can pop greater discounts since our curr is lesser than those and will always precede those popped while searchign
        auto x = prices[i]; // keep old price without discount
        if (!s.empty()) prices[i] -= s.top(); // apply the discount
        s.push(x); // push the old price as a potential most rececent discount
    }

    return prices;
}

// [8,4,6,2,3]