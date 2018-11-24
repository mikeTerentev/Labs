#include <iostream>
#include <vector>

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
    freopen("num2choose.in", "r", stdin);
    freopen("num2choose.out", "w", stdout);
    int n, k;
    long long nowNum = 0, m = 0;
    cin >> n >> k >> nowNum;
    long long tr[n + 1][k + 1];
    vector<long long> res(n);
    size_t z = 0;


    for (int mn = 0; mn <= n; mn++) {
        for (int mk = 0; mk <= k; mk++) {
            if (mn >= mk) {
                if (mk == 0 || mn == mk) {
                    tr[mn][mk] = 1;
                    //  cout << tr[mn][mk] << " ";
                    continue;
                }
                tr[mn][mk] = tr[mn - 1][mk - 1] + tr[mn - 1][mk];
                //cout << tr[mn][mk] << " ";
            }
        }
        //cout << endl;
    }

    long long sec = 1;
    while (k > 0) {
        int r = n - 1;
        long long isPoint = tr[n - 1][k - 1];
        if (isPoint >= nowNum + 1) {
            if (m > 0) {
                m += isPoint;
            }
            res[z] = sec;
            z++;
            k--;
        }
        if (nowNum >= isPoint) {
            m++;
            nowNum = nowNum - isPoint;
        }
        sec++;
        n = n - 1;
    }
    for (auto i = 0; i < z; i++) {
        cout << res[i] << " ";
    }
}