#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    unsigned long long n, s;
    int bit, bit2;
    cin >> n;
    unsigned long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> s;
    unsigned long long isNorm = 0;
    string res;
    if (s == 0) {
        cout << "1&~1";
        return 0;
    }
    unsigned long long x = a[0];
    bool ili_nado = false;
    unsigned long long check = (unsigned long long) (pow(2, 60)) - 1;
    for (int i = 0; i < 60; i++) {
        s & (1 << i) ? bit = 1 : bit = 0;
        if (bit == 1) {
            if (ili_nado) {
                res += "|";
            }
            ili_nado = true;
            bool i_nado = false;
            check = (unsigned long long) (pow(2, 60)) - 1;

            for (int j = 0; j < n; j++) {
                a[j] & (1 << i) ? bit2 = 1 : bit2 = 0;
                if (i_nado) res += "&";
                i_nado = true;
                if (bit2 == 0) {
                    res += "~" + to_string(j + 1);
                    check = check & ~a[j];
                } else {
                    res += to_string(j + 1);
                    check = check & a[j];
                }
            }
            isNorm = isNorm | check;
        }
    }
    if (isNorm == s) cout << res;
    else
        cout << "Impossible";
    return 0;
}