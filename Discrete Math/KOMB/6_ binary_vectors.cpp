#include <iostream>
#include<string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("vectors.in", "r", stdin);
    freopen("vectors.out", "w", stdout);
    int n, res = 0;
    cin >> n;
    vector<string> table(0);
    table.reserve(1 << n);
    string x;
    for (int curr = 0; curr < (1 << n); curr++) {
        x = "";
        bool flag = true;
        for (int i = 0; i < n; i++) {
            curr & (1 << i) ? x = '1' + x : x = '0' + x;
            if (i > 0) {
                if (x[1] == x[0] && x[1] == '1') {
                    flag = false;
                }
            }
        }
        if (flag) {
            table.push_back(x);
            res++;
        }
    }
    cout << res << endl;
    for (auto tmp:table) {
        cout << tmp << endl;
    }
    return 0;
}