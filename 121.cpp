#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() == 1) return 0;

    int g_max = 0, l_max = 0;
    int p1 = 0, p2 = 1;

    while (p2 < prices.size()) {
        while (p2 < prices.size() && prices[p2] > prices[p1]) {
            l_max = max(l_max, prices[p2] - prices[p1]);
            p2++;
        }

        g_max = max(g_max, l_max);
        p1 = p2;
        p2 = p2+1;
    }

    return g_max;
}

int main() {
    vector<int> prices({99, 100, 3, 98, 1, 2});
    cout << maxProfit(prices) << endl;
}