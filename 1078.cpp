#include <iostream>
#include <vector>
using namespace std;

vector<string> findOcurrences(string text, string first, string second) {
    text += " ";
    string w1 = "", w2 = "", w3 = "";
    vector<string> v;

    for (auto &c : text) {
        if (c == ' ') {
            if (w1 == first && w2 == second) {
                cout << "w1: " << w1 << ", w2: " << w2 << ", w3: " << w3 << endl;
                v.push_back(w3); 
                if (w2 == first && w3 == second) { w1 = w2; w2 = w3; }
                else if (w3 == first) { w2 = w3; w1 = ""; } 
                else w1 = w2 = "";
                w3 = "";
            }
            else if (w2 == first && w3 == second) { w1 = w2; w2 = w3; w3 = ""; cout << "found first 2\n"; }
            else if (w3 == first) { w2 = w3; w3 = ""; cout << "found first 1\n"; } 
            else w1 = w2 = w3 = "";
        }
        else w3 += c;
    }

    return v;
}


int main() {
    findOcurrences("obo jvezipre obo jnvavldde jvezipre jvezipre jnvavldde jvezipre jvezipre jvezipre y jnvavldde jnvavldde obo jnvavldde jnvavldde obo jnvavldde jnvavldde jvezipre", "jnvavldde", "y");
}