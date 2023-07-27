#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    vector<vector<int>> img2(img.size(), vector<int>(img[0].size()));
    for (int i = 0; i < img.size(); i++) {
        for (int j = 0; j < img[i].size(); j++) {
            int n = 1, sum = img[i][j];

            if (i-1 >= 0 && j-1 >= 0) { n++; sum += img[i-1][j-1]; }
            if (i-1 >= 0) { n++; sum += img[i-1][j]; }
            if (i-1 >= 0 && j+1 < img[i].size()) { n++; sum += img[i-1][j+1]; }
            if (j+1 < img[i].size()) { n++; sum += img[i][j+1]; }
            if (i+1 < img.size() && j+1 < img[i].size()) { n++; sum += img[i+1][j+1]; }
            if (i+1 < img.size()) { n++; sum += img[i+1][j]; }
            if (i+1 < img.size() && j-1 >= 0) { n++; sum += img[i+1][j-1]; }
            if (j-1 >= 0) { n++; sum += img[i][j-1]; }

            img2[i][j] = sum/n;
        }
    }

    return img2;
}