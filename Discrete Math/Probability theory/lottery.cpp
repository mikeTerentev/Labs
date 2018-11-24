#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    double res = 0;
    freopen("lottery.in", "r", stdin);
    freopen("lottery.out", "w", stdout);
    cin >> n >> m;
    int a, b[m + 1];
    b[0] = 0;
    double p = 1;
    for (auto i = 1; i <= m; ++i) {
        cin >> a >> b[i];
        res += p * (1 - ((double) 1 / (double) a)) * b[i - 1];
        p /= a;
    }
    cout << (double)n - (res + p * b[m]);
    return 0;
}