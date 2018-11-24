#include <iostream>
#include <vector>
#include <cmath>
#include <string>

# define s second
# define f first
using namespace std;

int main() {
    int e;
    int e2;
    bool pp[16][16];
    bool po[16][16];
    bool op[16][16];
    bool oo[16][16];
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            po[i][j] = false;
            op[i][j] = false;
            pp[i][j] = false;
            oo[i][j] = false;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, z;
        cin >> x >> z;
        if (x > 0 && z > 0) {
            pp[x - 1][z - 1] = true;
            pp[z - 1][x - 1] = true;
        }
        if (x > 0 && z < 0) {
            po[x - 1][abs(z) - 1] = true;
            op[abs(z) - 1][x - 1] = true;
        }
        if (x < 0 && z > 0) {
            op[abs(x) - 1][z - 1] = true;
            po[z - 1][abs(x) - 1] = true;
        }
        if (x < 0 && z < 0) {
            oo[abs(x) - 1][abs(z) - 1] = true;
            oo[abs(z) - 1][abs(x) - 1] = true;
        }
    }
    for (int i = 0; i < pow(2, n); i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int bit = 0, bit2 = 0;
                i & (1 << j) ? bit = 1 : bit = 0;
                i & (1 << k) ? bit2 = 1 : bit2 = 0;
                if (bit == 1 && bit2 == 1) {
                    if (oo[j][k]) {
                        flag = false;
                    }
                }
                if (bit == 0 && bit2 == 1) {
                    if (po[j][k]) {
                        flag = false;
                    }
                }
                if (bit == 1 && bit2 == 0) {
                    if (op[j][k]) {
                        flag = false;
                    }
                }
                if (bit == 0 && bit2 == 0) {
                    if (pp[j][k]) {
                        flag = false;
                    }
                }
            }

        }
        if (flag) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}