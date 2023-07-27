#include <iostream>
#include <string>
using namespace std;

// manually
int dayOfYear(string date) {
    int doy = 0;
    doy += stoi(date.substr(8, 2));

    int m = stoi(date.substr(5, 2));
    int y = stoi(date.substr(0, 4));
    

    switch (m) {
        case 12:
            doy += 30;
        case 11:
            doy += 31;
        case 10:
            doy += 30;
        case 9:
            doy += 31;
        case 8:
            doy += 31;
        case 7:
            doy += 30;
        case 6:
            doy += 31;
        case 5:
            doy += 30;
        case 4:
            doy += 31;
        case 3:
            if ((y % 4 == 0) && ((y % 400 == 0) || (y % 100 != 0))) doy += 29;
            else doy += 28;
        case 2:
            doy += 31;
    }

    return doy;
}


// or map
int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int dayOfYear(string dt) {
    int y = stoi(dt.substr(0, 4)), m = stoi(dt.substr(5, 2)), d = stoi(dt.substr(8));
    if (m > 2 && y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ++d; 
    while (--m > 0) d += days[m - 1];
    return d;
}

int main() {
    cout << dayOfYear("2016-12-31");
}