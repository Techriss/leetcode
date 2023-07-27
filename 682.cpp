#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calPoints(vector<string>& operations) {
    vector<int> v;
    int sum = 0;

    for (auto o : operations) {
        if (o == "D") { v.push_back(v[v.size()-1]*2); sum += v[v.size()-1]; }
        else if (o == "C") { sum -= v[v.size()-1]; v.pop_back(); }
        else if (o == "+") { v.push_back(v[v.size()-1] + v[v.size()-2]); sum += v[v.size()-1]; }
        else { v.push_back(stoi(o)); sum += v[v.size()-1]; }
    }

    return sum;
}