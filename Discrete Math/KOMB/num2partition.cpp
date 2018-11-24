#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long factorial(int x) {
    long long tmp = 1;
    for (int i = 2; i <= x; i++) {
        tmp *= i;
    }
    return tmp;
}

void comb(int mn, int mk, long long **tr) {
    for (int n = 0; n <= mn; n++) {
        for (int k = 0; k <= mk; k++) {
            if (k > n) continue;
            if (k == 0 || n == k) {
                tr[n][k] = 1;
            }
            tr[n][k] = tr[n - 1][k - 1] + tr[n - 1][k];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("brackets2num.in", "r", stdin);
    freopen("brackets2num.out", "w", stdout);
    int n, num;
    //  long long nowNum = 0, m = 0;
    string cur_C;
    cin >> cur_C;
    int m;
    n = cur_C.length() / 2;
    long long tr[2*n][2*n];
    tr[0][0] = 0;

    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (i == 0 && j == 0) {
                tr[i][j] = 1;
                continue;
            }
            if (i == 0 && j != 0) {
                tr[i][j] = 0;
                continue;
            }
            long long first = i - 1 < 0 || j - 1 < 0 ? 0 : tr[i - 1][j - 1];
            long long second = i - 1 < 0 ? 0 : tr[i - 1][j + 1];
            tr[i][j] = first + second;
            //  cout << i << " " << j << ":" << tr[i][j] << " || ";
        }
        // cout << endl;
    }

    long long res = 0;
    int length = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (cur_C[i] == ')') {
            int kol = 2 * n - i - 1;
          //  cout << i << ":" << kol << " ";
            int balance = length + 1;
            if (kol >= 0 || balance >= 0) {
                int z = tr[kol][balance];
                res += tr[kol][balance];
                for(int z=res;z<res+2;z++){
                    m++;
                }
               // cout << i << ":" << res << " ";
                length = length - 1;
            } else {
                res += 0;
            }
        } else {
            length++;
        }
    }

    cout << res;
}
