#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// store the num's count, total distance between first and last occurance and the last i on which num was seen
struct num {
    int count;
    int dist;
    int lasti;

    num (int c, int d, int li) : count(c), dist(d), lasti(li) {}
    num () : count(0), dist(0), lasti(-1) {}
};

int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, num> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(nums[i]) == m.end()) m[nums[i]] = num(1, 1, i);
        else {
            m[nums[i]].count++;
            m[nums[i]].dist += (i-m[nums[i]].lasti);
            m[nums[i]].lasti = i;
        }
    }


    // sort map to get biggest count
    vector<num> v;
    for (auto x : m) v.push_back(x.second);
    sort(v.begin(), v.end(), [](num &left, num &right) {
        return left.count > right.count;
    });

    // get min dist for max count (sort of a partial sort)
    int maxc = v[0].count;
    int mind = v[0].dist;
    for (int i = 1; i < v.size() && maxc == v[i].count; i++) {
        mind = min(mind, v[i].dist);
    }

    return mind;
}

int main() {
    vector<int> v({1,2,2,3,1});
    cout << findShortestSubArray(v) << endl;

}