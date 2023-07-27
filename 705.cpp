#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
public:
    MyHashSet() {
        size = 32768;
        v = vector<vector<int>>(size, vector<int>());
    }
    
    void add(int key) {
        int h = hash(key);

        for (auto &x : v[h]) {
            if (x == key) return;
        }

        v[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        
        for (int i = 0; i < v[h].size(); i++) {
            if (v[h][i] == key) v[h].erase(v[h].begin() + i);
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        
        for (auto x : v[h]) {
            if (x == key) return true;
        }

        return false;
    }

private:
    vector<vector<int>> v;
    int size;
    int n;

    int hash(int key) {
        return key % size;
    }
};


int main() {
    MyHashSet* obj = new MyHashSet();
    obj->add(1);
    cout << obj->contains(1) << endl;
}