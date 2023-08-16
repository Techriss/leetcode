#include <iostream>
#include <vector>
using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        v = vector<int>({0, big, medium, small});
    }
    
    bool addCar(int carType) {
        if (v[carType]) { v[carType]--; return true; }
        else return false;
    }

    vector<int> v;
};