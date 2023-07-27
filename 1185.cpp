#include <iostream>
#include <string>
#include <vector>
using namespace std;

// zeller's algorithm (congruence)
string dayOfTheWeek(int day, int month, int year) {
    int century = year / 100;
    int yoc = year % 100;

    if (month == 1 || month == 2) { month += 12; year--; }

    int h = (day + (13 * (month + 1) / 5) + yoc + (yoc / 4) + (century / 4) - (2 * century)) % 7;
    vector<string> v({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"});
    return v[h];
}

// zeller's algorithm (congruence)
string dayOfTheWeek(int d, int m, int y, int c = 0) {
    vector<string> days= {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    if (m < 3) m += 12, y -= 1;
    c = y / 100, y = y % 100;
    int w = ((c / 4) - (2 * c) + y + (y / 4) + (13 * (m + 1) / 5) + d - 1) % 7;
    return days[(w + 7) % 7];
}


// solution without knowing anything but the current date
class Solution {
public:
    bool leap(int y) {
        return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
    }
    
    int find(int d, int m, int y) {
        vector<int> days = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        int c = 0;

        // take any base year less than all the inputs
        for (int my = 1940; my < y; my++) {
            c += 365 + leap(my);
        }

        if (leap(y)) days[1] += 1;
        for (int i = 0; i < m-1; i++) c += days[i];
        c += d;

        return c;
    }

    string dayOfTheWeek(int d, int m, int y) {
        // start from today's day (i.e I have taken 28/10/2020 , so on 28/10/2020 Wednesday, hence start from here
        // you can take any date and corresponding day

        vector<string> day={"Wednesday","Thursday","Friday","Saturday","Sunday","Monday","Tuesday"};
        
        int knownstart = find(28,10,2020);
        int d = find(d, m, y);
        
        return day[(d - knownstart) % 7];
    }
};