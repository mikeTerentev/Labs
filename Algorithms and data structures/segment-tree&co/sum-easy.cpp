#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sum0.in", "r", stdin);
    freopen("sum0.out", "w", stdout);
    int n, x, y, a0;
    int m, z, t, b0;
    cin >> n >> x >> y >> a0;
    cin >> m >> z >> t >> b0;

    long long res = 0;
    vector<long long> a(0);
    a.reserve(n);
    int bin = 1 << 16;

    a.push_back(a0);

    vector<int> c(0);
    c.reserve(2 * m);

    int last = a[0], cur;
    for (auto i = 1; i < n; i++) {
        cur = (x * last + y) % bin;
        a.push_back(a[i - 1] + cur);
        last = cur;
    }

    bin = 1 << 30;
    last = b0;
    c.push_back(last % n);
    for (int i = 1; i < 2 * m; i++) {
        last = (z * last + t) % (bin);
        if (last < 0) last += bin;
        c.push_back(last % n);
    }

    for (int i = 0; i < m; i++) {
        int s = min(c[2 * i], c[2 * i + 1]);
        res += s == 0 ? a[max(c[2 * i], c[2 * i + 1])] : a[max(c[2 * i], c[2 * i + 1])] - a[s - 1];
    }
    cout << res;
    return 0;
}
