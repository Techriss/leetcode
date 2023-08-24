#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>
using namespace std;

// with word checking
bool is_number(const std::string & s){
    return std::regex_match(s, regex("[0-9]+"));
}


bool areNumbersAscending(string s) {
    istringstream iss(s);
    string w;

    int prev = 0;
    while (iss >> w) {
        if (is_number(w)) {
            int n = stoi(w);
            if (prev < n) prev = n;
            else return false; 
        }
    }

    return true;
}



// with character checking
bool areNumbersAscending(string s) {
    int prev = 0, curr = 0;
    for (auto &c : s) {
        if (isdigit(c)) curr = curr*10 + (c-'0');
        else if (curr != 0) {
            if (prev >= curr) return false;
            prev = curr;
            curr = 0;
        }
    }

    return curr == 0 || prev < curr;
}


// trick with stream but only checking first char
bool areNumbersAscending(string s) {
    istringstream iss(s);
    string w;

    int prev = 0;
    while (iss >> w) {
        if (isdigit(w[0])) {
            int n = stoi(w);
            if (prev < n) prev = n;
            else return false; 
        }
    }

    return true;
}