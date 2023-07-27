#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    const int n = nums.size();
    if (n == 0) return ranges;

    int l = nums[0], r = nums[0];
    string range = "";

    for (int i = 1; i < n; i++) {
        if (r + 1 == nums[i]) r++;
        else if (l != r) {
            range += to_string(l);
            range += "->";
            range += to_string(r);
            ranges.push_back(range);
            range = "";

            l = nums[i];
            r = nums[i];
        }
        else {
            ranges.push_back(to_string(l));
            l = nums[i];
            r = nums[i];
        }
    }

    if (l != r) {
        range += to_string(l);
        range += "->";
        range += to_string(r);
        ranges.push_back(range);
        range = "";
    }
    else {
        ranges.push_back(to_string(l));
    }

    return ranges;
}

int main() {
    vector<int> v({0,2,3,4,6,8,9});
    auto r = summaryRanges(v);
    for (auto x : r) cout << x << endl;
}