#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
public:
    MyHashMap() {
        size = 10007;
        v = vector<vector<pair<int, int>>> (size, vector<pair<int, int>>());
    }
    
    void put(int key, int value) {
        int h = hash(key);

        for (auto &p : v[h]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }

        v[h].push_back({key, value});
    }
    
    int get(int key) {
        int h = hash(key);
        
        for (auto p : v[h]) {
            if (p.first == key) return p.second;
        }

        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);

        for (int i = 0; i < v[h].size(); i++) {
            if (v[h][i].first == key) {
                v[h].erase(v[h].begin() + i);
                return;
            }
        }
    }

private:
    int size;
    vector<vector<pair<int, int>>> v;

    int hash(int key) {
        return key % size;
    }
};