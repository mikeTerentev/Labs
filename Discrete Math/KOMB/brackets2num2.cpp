
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("brackets2num2.in", "r", stdin);
    freopen("brackets2num2.out", "w", stdout);

    string psp;
    cin >> psp;

    int n = psp.size() / 2;

    long long blncUp = 0, blncDown = 0, num = 0, last, sum;
    vector<char> mem(0);
    int fullsize = psp.size();
    mem.reserve(psp.size());
    vector<vector<long long>> d(2 * n + 10);

    for (auto j = 0; j <= fullsize; j++) d[fullsize].push_back(0);
    d[fullsize][0] = 1;

    for (auto i = fullsize - 1; i > -1; i--) {
        d[i].push_back(d[i + 1][1]);
        for (auto j = 1; j < fullsize; j++) {
            d[i].push_back(d[i + 1][j + 1] + d[i + 1][j - 1]);
        }
        d[i].push_back(0);
    }

    for (auto ptr = 0; ptr < fullsize; ptr++) {
        long long cursize = fullsize - ptr;
        blncUp = d[ptr + 1][mem.size() + 1] * (1LL << ((n - 1) - (ptr + mem.size()) / 2));
        if (cursize == mem.size()) mem.pop_back();
        else {
            if (mem.size() == 0) {
                if (psp[ptr] == '[') num = num + blncUp;
                mem.push_back(psp[ptr]);

            } else {
                blncUp = (1LL << ((n - 1) - (ptr + mem.size()) / 2)) * d[ptr + 1][mem.size() + 1];
                blncDown = (1LL << (n - (ptr + mem.size()) / 2)) * d[ptr + 1][mem.size() - 1];
                sum = blncDown + blncUp;

                if (mem.back() == '(') {
                    switch (psp[ptr]) {
                        case '(':
                            mem.push_back('(');
                            break;
                        case '[':
                            mem.push_back(')');
                            num = num + sum;
                            break;
                        case ')':
                            mem.pop_back();
                            num = num + blncUp;
                            break;
                        default:
                            break;
                    }
                } else {
                    switch (psp[ptr]) {
                        case '(':
                            mem.push_back('(');
                            break;
                        case '[':
                            mem.push_back(')');
                            num = num + blncUp;
                            break;
                        default:
                            mem.pop_back();
                            num = num + (blncUp + blncUp);
                            break;
                    }
                }
            }
        }
    }
    cout << num;
    return 0;
}