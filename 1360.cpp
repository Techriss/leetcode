#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool leap(int y) {
    return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
}

// -
int daysBetweenDates(string date1, string date2) {
    vector<int> mdays({0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
    int days = 0;

    int y1 = stoi(date1.substr(0, 4));
    int y2 = stoi(date2.substr(0, 4));
    int m1 = stoi(date1.substr(5, 2));
    int m2 = stoi(date2.substr(5, 2));
    int d1 = stoi(date1.substr(8, 2));
    int d2 = stoi(date2.substr(8, 2));

    if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)) {
        swap(y1, y2);
        swap(m1, m2);
        swap(d1, d2);
    }

    // add years in between
    for (int y = y1+1; y < y2; y++) days += (365 + leap(y));
    if (y1 != y2) {
        // move to new year
        if (leap(y1) && m1 <= 2) days++;
        for (int m = m1+1; m <= 12; m++) days += mdays[m];
        days += mdays[m1]-d1;

        // move from new year to date 2
        if (leap(y2) && m2 > 2) days++;
        for (int m = 1; m < m2; m++) days += mdays[m];
        days += d2;
    }
    else if (m1 != m2) {
        days += mdays[m1]-d1;
        if (leap(y1) && m1 <= 2 && m2 > 2) days++;
        for (int m = m1+1; m < m2; m++) days += mdays[m];
        days += d2;
    }
    else {
        days += d2-d1;
    }

    return days;
}


// or to_days-to_days
class Solution {   
    public:
        int daysBetweenDates(string date1, string date2) {
            return abs(date_to_int(date2) - date_to_int(date1));
        }
        
    protected:
        int date_to_int(string s_date)
        {
            int Y = stoi(s_date.substr(0, 4));
            int M = stoi(s_date.substr(5, 2));
            int D = stoi(s_date.substr(8, 2));
            
            int date = 0;
            for(int y = 1971; y < Y; ++y) date += is_leap_year(y) ? 366 : 365;
            for(int m = 1; m < M; ++m) date += days_in_month(m, Y);
            return date + D;
        }
        
        bool is_leap_year(int year)
        {
            return (year %4  == 0 && year % 100 != 0) || year % 400 == 0;
        }
        
        int days_in_month(int m, int year)
        { 
            if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12 ) return 31;
            if(m==2) return is_leap_year(year) ? 29 : 28;
            return 30;
        }
};


int main() {
    cout << daysBetweenDates("2020-01-15", "2020-02-15") << endl;
}