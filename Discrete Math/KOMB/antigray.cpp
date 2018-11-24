#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("antigray.in", "r", stdin);
    freopen("antigray.out", "w", stdout);
    int n;
    cin >> n;
    string num = "";
    int all = (int) pow(3, n - 1);
    for (int cur = 0; cur < all; cur++) {
        num = "";
        int tm = cur;
        int ptr = 0;
        while (tm > 0) {
            char x = (char) ('0' + tm % 3);
            num = x + num;
            tm = tm / 3;
            ptr++;
        }
        while (ptr < n) {
            num = '0' + num;
            ptr++;
        }
        cout << num << endl;
        for (int i = 1; i <= 2; i++) {
            for (int x = 0; x < n; x++) {
                cout << ((int) (num[x] - '0') + i) % 3;
            }
            cout << endl;
        }
    }
    return 0;
}