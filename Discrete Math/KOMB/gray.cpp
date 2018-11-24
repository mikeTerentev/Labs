#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("gray.in", "r", stdin);
    freopen("gray.out", "w", stdout);
    int n;
    cin >> n;
    char table[(1<<n)+1][n+1];
    table[1][n] = '0';
    table[2][n] = '1';
    int now = 0;
    int back = 0;
    now++;
    now++;
    ///////////////////
    for (auto i =now; i <n + 1; i++) {
        back = now;
        now *= 2;
        ///////////////
        for (auto forward = now /2 + 1; forward <now + 1; forward++) {
            for (auto inbox = 1; inbox <=n; inbox++) {
                table[forward][inbox] = table[back][inbox];
            }
            int sec = n + 1;
            int box= sec - i;
            back--;
            table[forward][box] = '1';
            table[back + 1][box] = '0';

        }
    }
    ///////
    int v = (1 << n);
    for (auto i = 1; i < v+1; i++) {
        for (auto j = 1; j < n+1; j++) {
            cout << table[i][j];
        }
        cout << endl;
    }

    return 0;
}