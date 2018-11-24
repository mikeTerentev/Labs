#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    freopen("bwt.in", "r", stdin);
    freopen("bwt.out", "w", stdout);
    cin >> s;
    int n = s.size() - 1;
    string m[1000];
    m[0] = s;
    for (int i = 1; i <= n; i++) {
        m[i] = m[i - 1][n] + m[i - 1].substr(0, n);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            const char *x = m[i].c_str();
            const char *x2 = m[j].c_str();
            if (!(strcmp(x, x2) <= 0)) {
                swap(m[j], m[i]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << m[i][n];
    }
    return 0;
}
