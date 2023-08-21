#include <iostream>
#include <vector>
using namespace std;

// simulation O(n^2)
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    const int n = students.size();
    int l = 0;
    for (int i = 0; i < n && l < n*n; i++) {
        if (sandwiches[i] != students[l]) { students.push_back(students[l]); i--; }
        ++l;
    }

    return students.size() - l;
}


// mixed count
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    const int n = sandwiches.size();
    vector<int> s(2, 0);
    int l = 0;

    for (int i = 0; i < n; i++) {
        if (l >= n) {
            if (s[sandwiches[i]] == 0) return n-i;
            else s[sandwiches[i]]--;
        }
        else if ((l < n && sandwiches[i] != students[l])) {
            s[students[l]]++;
            i--;

        }
        l++;
    }

    return 0;
}

// only count
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    const int n = sandwiches.size();
    int i;
    vector<int> s(2, 0);

    for (auto &x : students) ++s[x];
    for (i = 0; i < n && s[sandwiches[i]] > 0; i++) s[sandwiches[i]]--;

    return n-i;
}