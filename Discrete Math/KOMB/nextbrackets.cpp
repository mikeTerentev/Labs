#include <iostream>
#include <vector>
#include <string>

using namespace std;

void out(string a, int n) {
    for (auto i = 0; i < n; i++) {
        cout << a[i];
    }
}

void fall() {
    cout << '-';
    cout << endl;
}

void put_close() {
    cout << ')';
}

void put_open() {
    cout << '(';
}

int main() {
    int balance = 0;
    int open = 0;
    string a, m = "";
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("nextbrackets.in", "r", stdin);
    freopen("nextbrackets.out", "w", stdout);
    cin >> a;
    int kmax = a.size() - 1;
    for (int i = 0; i <= kmax; i++) {
        if (i % 2 == 0) {
            m += '(';
        } else {
            m += ')';
        }
    }
    if (m == a) {
        fall();
        return 0;
    }
    for (int i = kmax; i > 0; i--) {
        if (a[i] == ')') {
            balance--;
        }
        if (a[i] == '(') {
            open++;
            balance++;
            if (balance < 0) {
                break;
            }
        }

    }

    int lim = a.size() - open - (open - balance);
    if (lim == 0) {
        fall();
        return 0;
    }
    out(a, lim);
    put_close();
    for (auto i = 0; i < open; i++) {
        put_open();
    }
    for (auto i = 0; i < open - balance - 1; i++) {
        put_close();
    }
    return 0;
}