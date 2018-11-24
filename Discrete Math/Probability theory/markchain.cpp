#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iomanip>

using namespace std;


int main() {
    int n;
    freopen("markchain.in", "r", stdin);
    freopen("markchain.out", "w", stdout);
    cin >> n;
    long double x, element;

    long double curr_m[n][n], start_matrix[n][n];

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            cin >> curr_m[i][j];
            start_matrix[i][j] = curr_m[i][j];
        }
    }
    long double new_m[n][n], delta = 0;
    while (true) {
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                element = 0;
                for (auto p = 0; p < n; p++) {
                    element += curr_m[i][p] * curr_m[p][j];
                }
                new_m[i][j] = element;

                if (abs(new_m[i][j] - curr_m[i][j]) > delta || (i == 0 && j == 0)) {
                    delta = abs(new_m[i][j] - curr_m[i][j]);
                }
            }
        }
        for (auto j = 0; j < n; ++j) {
            for (auto i = 0; i < n; ++i) {
                curr_m[j][i] = new_m[j][i];
            }
        }
        if (delta < 1e-4) {
            break;
        }
    }
    for (int i = 0; i <n ; ++i) {
        cout << setprecision(5) << curr_m[0][i] << endl;
    }
    return 0;
}