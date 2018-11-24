#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

# define v second
# define t first
using namespace std;

int main() {
    int n, l;

    freopen("trains.in", "r", stdin);
    freopen("trains.out", "w", stdout);

    cin >> l >> n;
    int zn = n + 2;
    vector<pair<int, int>> tt = vector<pair<int, int>>(zn);
    int destline[1003];
    int timeline[1003];
    destline[0] = 0;
    timeline[0] = 0;

    tt[0].v = 0;
    tt[0].t = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> tt[i].t >> tt[i].v;
    }
    for (int i = 1; i <= n; ++i) {
        int run = tt[i].v * tt[i].t;
        destline[i] = destline[i - 1] + run;
        timeline[i] = timeline[i - 1] + tt[i].t;
    }
    destline[n + 1] = destline[n];
    timeline[n + 1] = timeline[n];
    double right = 12099;
    double left = 0;


    while (true) {
        bool rule = true;
        if ((right - left) < 0.00001) {
            cout << setprecision(3) << fixed << right;
            break;
        }
        double midd = (right + left) / 2;

        for (int i = 1; i < tt.size(); ++i) {

            double interval = midd + timeline[i - 1];
            int k2 = 1;
            while (interval > 0 && k2 < tt.size() - 1) {
                interval -= tt[k2].t;
                k2++;
            }

            k2--;

            double partDist = 0;

            if (interval <= 0) {
                double run = (double) (tt[k2].t + interval) * (double) tt[k2].v;
                int s = k2 - 1;
                partDist = (double) destline[s] + run;
            } else {
                partDist = INT_MAX;
            }

            if ((double) partDist - destline[i - 1] < l) {
                rule = false;
                break;
            }
        }


        for (int i = 1; i < tt.size(); ++i) {
            double interval = midd;
            int k = i;
            while (interval > 0 && k > 0) {

                interval -= tt[k].t;
                k--;
            }
            double partDist2 = 0;

            if (interval <= 0) {
                interval = -interval;
                double run = (double) (interval) * (double) tt[k + 1].v;
                partDist2 = (double) destline[k] + run;
            } else {
                partDist2 = INT_MIN;
            }


            if ((double) destline[i] - partDist2 < l) {
                rule = false;
                break;
            }
        }


        if (rule) {
            right = midd;
        } else {
            left = midd;
        }
    }
    return 0;
}




