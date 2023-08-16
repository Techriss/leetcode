#include <iostream>
#include <vector>
using namespace std;

int minOperations(vector<string>& logs) {
    int level = 0;
    for (auto &op : logs) {
        if (op == "../") level = max(0, level-1);
        else if (op != "./") level++;
    }

    return level;
}