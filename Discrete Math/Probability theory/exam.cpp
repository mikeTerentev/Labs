#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("exam.in", "r", stdin);
    freopen("exam.out", "w", stdout);
    cout.precision(5);
    int n, k;
    cin >> k >> n;
    double result = 0;
    int p, m;
    for (auto i = 0; i < k; ++i) {
        cin >> p >> m;
        result += (double(p) / double(n)) * (double(m) / 100);
    }
    cout << result;
    return 0;
}