#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> v;
    vector<pair<string, int>> mv;
    unordered_map<string, int> m;

    for (int i = 0; i < list1.size(); i++) m[list1[i]] = i+1; 
    for (int i = 0; i < list2.size(); i++) if (m.find(list2[i]) != m.end()) m[list2[i]] += i+1;
    for (int i = 0; i < list1.size(); i++) if (m[list1[i]] == i+1) m.erase(list1[i]);

    for (auto x : m) mv.push_back(x);
    sort(mv.begin(), mv.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });

    if (mv.empty()) return v;
    v.push_back(mv[0].first);
    for (int i = 1; i < mv.size() && mv[i].second == mv[0].second; i++) v.push_back(mv[i].first);
    return v;
}


int main() {
    vector<string> v1({"happy","sad","good"});
    vector<string> v2({"sad","happy","good"});

    auto ans = findRestaurant(v1, v2);

}