#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// no extra memory
string reorderSpaces(string text) {
    int spaces = 0, words = 0;
    char last = ' ';

    for (auto &c : text) {
        if (c == ' ') spaces++;
        else if (last == ' ') words++;
        last = c;
    }

    int per = words == 1 ? 0 : spaces / (words-1);
    string s = "";

    int i = 0; 
    while (text[i] == ' ') i++;
    while (i < text.size()) {
        if (text[i] != ' ') { s += text[i]; i++; }
        else if (spaces >= per) {
            for (int j = 0; j < per; j++) { s += ' '; spaces--; }
            i++;
            while (i < text.size() && text[i] == ' ') i++;
        }
        else break;
    }

    while (spaces --> 0) s += ' ';
    return s;
}


// storing words
string reorderSpaces(string text) {
    int spaces = 0;
    string word, s;
    vector<string> words;

    for (auto &c : text) {
        if (c == ' ') {
            ++spaces;
            if (!word.empty()) words.push_back(word);
            word = "";
        }
        else word += c;
    }
    if (!word.empty()) words.push_back(word);
    if (words.size() == 1) return words.back() + string(spaces, ' ');

    int gap = spaces / (words.size() - 1), suff = spaces % (words.size() - 1);
    for (auto w : words)
        s += w + string(gap, ' ');

    return s.substr(0, s.size() - gap) + string(suff, ' ');
}

// same thing, may look cleaner via stream
string reorderSpaces(string text) {
	string s, ans;
	vector<string> words;
	istringstream iss(text);

	while (iss >> s) words.push_back(s);
	const int space = count(text.begin(), text.end(), ' ');
	const int n = words.size();
	const int quot = n==1 ? 0 : space / (n-1), rem = n == 1 ? space : space % (n-1);

	for (auto &w : words){
        if (!ans.empty()) ans += string(quot, ' ');
        ans += w;
	}

	ans += string(rem,' ');
	return ans;
}

int main() {
    cout << reorderSpaces("  this   is  a sentence ");
    cout << "xxx" << endl;
}