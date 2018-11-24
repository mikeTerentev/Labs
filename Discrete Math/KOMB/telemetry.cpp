#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

void nextNum(int &num, int &curmax, int &k) {
    num = num % curmax;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("telemetry.in", "r", stdin);
    freopen("telemetry.out", "w", stdout);
    int size, k;
    cin >> size >> k;
    int maxk = pow(k, size + 1), num, curmax, tmp, delta = 0;
    string res;
    for (int i = 0; i < maxk / k; i++) {
        curmax = maxk / k / k;
        num = i;
        res = "";
        int j = 1;
        int thisN;
        while (j < size + 1) {
            delta = num / curmax;
            tmp = curmax * k;
            if (i / tmp % 2 != 1) {
                res = res + (char) ('0' + delta);
            } else {
                thisN = k - delta - 1;
                res = res + char('0' + thisN);
            }
            //  cout << j << ':' << res << endl;
            if (thisN < 0) {
                cout << "thisN < 0" << j << " i=" << i << endl;
            }
            nextNum(num, curmax, k);
            curmax = curmax / k;
            j++;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }

}
