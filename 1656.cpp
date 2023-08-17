#include <iostream>
#include <vector>
using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) {
        v = vector<string>(n+2);
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> res;
        v[idKey] = value;
        if (p != idKey) return res;

        while (!v[p].empty()) res.push_back(v[p++]);
        return res;
    }


private:
    vector<string> v;
    int p = 1;
};