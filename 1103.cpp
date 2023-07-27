#include <iostream>
#include <vector>
using namespace std;

// simply simulate
vector<int> distributeCandies(int candies, int num_people) {
    vector<int> v(num_people, 0);

    for (int l = 0; candies > 0; l++) {
        for (int i = 0; candies > 0 && i < num_people; i++) {
            int res = min(l*num_people + i+1, candies);
            v[i] += res;
            candies -= res;
        }
    }

    return v;
}


// or use some math
vector<int> distributeCandies(double candies, int num_people) {
	vector<int> res(num_people, 0);

	double total = floor((-1 + sqrt(1 + 8 * candies)) / 2);
	int round = floor(total / num_people);

	for (int i = 1; i <= num_people; i++)
	{
		int first = i;
		int last = first + num_people * (round - 1);
		int inComplete = candies - (num_people+last) * (num_people + last - 1) / 2;
		res[i - 1] = (first + last) * round / 2 + max(min(last + num_people, inComplete), 0);
	}

	return res;
}


// or loop till no candies and distrbute based on the remainder (best solution)
vector<int> distributeCandies(int candies, int num_people) {
    vector<int> res(num_people);
    // index always increases by one, but we add its value to arr[remainder], thus always in the right place
    for ( int index = 0; candies > 0; ++index, candies -= index )
        res[index % num_people] += min(index + 1, candies);
    return res;
}

int main() {
    distributeCandies(10, 3);
}