#include <iostream>
#include <vector>
using namespace std;

bool isOneBitCharacter(vector<int>& bits) {
    int c = 0;
    for (int i = bits.size()-2; i >= 0 && bits[i] == 1; i--) c++;
    return (c % 2 == 0);   
}