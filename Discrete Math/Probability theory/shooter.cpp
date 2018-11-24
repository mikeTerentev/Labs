#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shooter.in", "r", stdin);
    freopen("shooter.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    double p[n];
    cout.precision(13);
    double re = 0, temp = 0;
    for (auto i = 0; i < n; ++i) {
        cin >> temp;
        p[i] = 1 - temp;
        double temo = p[i];
        for (auto z = 0; z < m - 1; ++z) { p[i] *= temo; }
        re += p[i];
    }
    cout << (re != 0 ? p[k - 1] / re : 0);
    return 0;
}