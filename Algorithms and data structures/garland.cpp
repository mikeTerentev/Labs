#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
   freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    int n;
    double a;
    cin >> n >> a;
    double right = 1000000;
    double left = 0;
    double min = INT_MAX;
    while (true) {
    //    cout<<left<<" "<<right<<'/n';
        if (right-left<0.0000001) {
            cout <<fixed << setprecision(2) << min;
            break;
        }
        double midd = (left + right) / 2;
        double f1 = a;
        bool flag = true;
        double f2 = midd;
        for (int i = 3; i != n + 1; i++) {
            double x = f2;
            f2 = 2 * f2 - f1 + 2;
            f1 = x;
            if (f2 <= 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (min > f2) min = f2;
            right = midd;
        } else {
            left = midd;
        }
    }

    return 0;
}
