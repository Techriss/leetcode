#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

string reformatDate(string date) {
    date += ' ';
    vector<string> v;
    string word = "";
    unordered_map<string, string> m({
        {"Jan", "01" }, 
        {"Feb", "02" }, 
        {"Mar", "03" }, 
        {"Apr", "04" }, 
        {"May", "05" }, 
        {"Jun", "06" }, 
        {"Jul", "07" }, 
        {"Aug", "08" }, 
        {"Sep", "09" }, 
        {"Oct", "10" }, 
        {"Nov", "11" }, 
        {"Dec", "12" }
        });

    for (auto &c : date) {
        if (c == ' ') { v.push_back(word); word = ""; }
        else word += c;
    }


    string s = "";
    s += v[2];
    s += '-';
    s += m[v[1]];
    s += '-';
    if (v[0].size() == 3) s += '0';
    s += v[0].substr(0, v[0].size()-2);
    return s;
}

// or stream
string reformatDate(string date) {
    unordered_map<string, string> months = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},{"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"},{"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
    istringstream s(date); 
    string day; s >> day;
    day.pop_back(); day.pop_back();
    if (day.size() == 1)
        day = "0" + day;
    string month; s >> month;
    string year; s >> year;
    return year + "-" + months[month] + "-" + day;
}