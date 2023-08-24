#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
    i is most forward, marks last vowel
    j is most backward, marks first vowel
    k marks the start of a window [k, i] which has exactly 5 unique vowels in it

    vow is the current number of unique vowels
*/
int countVowelSubstrings(string word) {
    int vow = 0, res = 0;
    unordered_map<char, int> m;
    string vowels = "aeiou";

    for (int i = 0, j = 0, k = 0; i < word.size(); i++) {
        if (vowels.find(word[i]) != string::npos) {
            vow += (++m[word[i]] == 1);

            // we increment k in search for a smaller window [k, i] which still has all vowels
            // end result is that the current smallest window is [k-1, i]
            while (vow == 5) vow -= --m[word[k++]] == 0;

            // we add the difference between k and j as all potentially larger windows than the smallest possible one
            // in other words, we add all other k-j possibilities of choosing a window  containing [k-1, j]
            // every time we find a new vowel
            res += k-j;
        }
        else {
            // make i, j, k equal
            m.clear();
            vow = 0;
            j = k = i+1;
        }
    }

    return res;
}





// 5 unique minus 4 unique
bool isVowel(char ch) {
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}

int count_Vowel_At_Most_K_Unique_Vowels(string s,int k){
    unordered_map<char,int> freq;
    int count = 0;
    int i = 0, j = 0;
    while (j < s.size()) {
        // new window
        if (!isVowel(s[j])) {
            i = j+1;
            j++;
            freq.clear();
        }
        else {
            // stretching window to fit unique vowels by incrementing j
            freq[s[j++]]++;

            // while there are k unique vowels, increment i (i is when a new window with k unique vowels starts)
            while (freq.size() > k) {
                freq[s[i]]--;
                if (freq[s[i]] == 0)
                    freq.erase(s[i]);
                i++;
            }

            // here, we add how many substrings with AT MOST k unique vowels there are
            count += (j-i + 1);
        }
    }
    return count;
}

int countVowelSubstrings(string word) {
    return (count_Vowel_At_Most_K_Unique_Vowels(word, 5) - count_Vowel_At_Most_K_Unique_Vowels(word, 4));   
}







// brute (very very slow)
int countVowelSubstrings(string word) {
    int res = 0, n = word.size();
    for (int i = 5; i <= n; i++) {
        for (int j = 0; j+i <= n; j++) {

            string sub = word.substr(j, i);
            
            unordered_set<char> m(sub.begin(), sub.end());
            if (m.size() == 5 && m.count('a') && m.count('e') && m.count('i') && m.count('o') && m.count('u')) ++res;
        }
    }

    return res;
}









int main() {
    cout << countVowelSubstrings("cuaieuouac") << endl;
}