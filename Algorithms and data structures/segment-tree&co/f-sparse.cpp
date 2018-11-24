#include <iostream>
#include <vector>

using namespace std;

int fl(int len) {
    int k = 0;
    while ((1 << k) <= len) k++;

    k--;
    return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sparse.in", "r", stdin);
    freopen("sparse.out", "w", stdout);
    int n, m, u, v;
    cin >> n;
    vector<int> a(static_cast<unsigned long>(n ));
    vector<vector<int>> d(static_cast<unsigned long>(n));
    cin >> m >> a[0] >> u >> v;


    int pow = 0;
    int tmp = 1;
    while (tmp < n) {
        tmp <<= 1;
        pow++;
    }

    d[0].push_back(a[0]);
    for (auto i = 1; i < n; i++) {
        a[i] = (23 * a[i - 1] + 21563) % 16714589;
        d[i].push_back(a[i]);
    }
    for (auto j = 1; j <= pow; j++) {
        for (auto i = 0; i < n; i++) {
            d[i].push_back(min(d[i][j - 1],
                               d[min(i + (1 << (j - 1)), n - 1)][j - 1]));
        }
    }

    vector<int> pre(static_cast<unsigned long>(n + 1));
    for (auto i = 0; i <= n; i++) {
        pre[i] = fl(i);
    }

    int r = max(u, v);
    int l = min(u, v) - 1;
    int len = r - l;
    int anslast = min(d[l][pre[len]], d[r - (1 << pre[len])][pre[len]]);

    for (auto i = 1; i < m; i++) {
        u = ((17 * u + 751 + anslast + 2 * i) % n) + 1;
        v = ((13 * v + 593 + anslast + 5 * i) % n) + 1;
        r = max(u, v);
        l = min(u, v) - 1;
        len = r - l;
        anslast = min(d[l][pre[len]], d[r - (1 << pre[len])][pre[len]]);
    }
    cout << u << " " << v << " " << anslast;
    return 0;
}