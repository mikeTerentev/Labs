#include <iostream>
#include <string>

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
    freopen("num2brackets.in", "r", stdin);
    freopen("num2brackets.out", "w", stdout);
    int n, num, balance = 0;
    string res = "";
    //  long long nowNum = 0, m = 0;
    long long k;
    cin >> n;
    cin >> k;
    long long tr[2 * n + 1][2 * n + 1];
    tr[0][0] = 0;

    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
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
    char open = '(';
    char close = ')';
    for (int i = 0; i < 2 * n; i++) {
        int nextbalance = balance + 1;
        int prebalance = balance - 1;
        int all_pre = 2 * n - i - 1;
        if (tr[all_pre][nextbalance] <= k) {
            cout << close;
            balance = prebalance;
            k -= tr[all_pre][nextbalance];
            continue;
        }
        if (tr[all_pre][nextbalance] > k) {
            cout << open;
            balance = nextbalance;
        }
    }
}