#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    freopen("decode.in", "r", stdin);
    freopen("decode.out", "w", stdout);
    string s;
    int a[500];
    vector<char> res(0);
    for (int i = 0; i < 400; i++) {
        a[i] = -1;
    }
    cin >> s;
    int l = 0;
    for (int i = 0; i < s.length(); i++) {
        if (res.empty()) {
            res.push_back(s[i]);
            l++;
        } else {
            if (res[l - 1] == s[i]) {
                res.pop_back();
                l--;
            } else {
                res.push_back(s[i]);
                l++;
            }
        }
    }
    for (char x: res) {
        cout << x;
    }
    return 0;
}