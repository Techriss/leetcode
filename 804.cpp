#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// can use set or map
int uniqueMorseRepresentations(vector<string>& words) {
    unordered_set<string> m;
    vector<string> morse({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});
    for (auto &w : words) {
        string s = "";
        for (auto &c : w) s += morse[c-97];
        m.insert(s);
    }

    return m.size();
}