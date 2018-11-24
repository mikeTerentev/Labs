#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("nextvector.in", "r", stdin);
    freopen("nextvector.out", "w", stdout);
    vector<char> v(0);
    v.reserve(200000);
    vector<char> v2(0);
    v2.reserve(200000);
    char tmp;
    while (cin >> tmp) {
        v.push_back(tmp);
        v2.push_back(tmp);
    }
    int ptr = v.size() - 1;
    bool OK = true;
    if (v2[ptr] == '1') OK = false;
    while (ptr > -1 && OK) {
        v2[ptr] = '1';
        ptr--;
        if (v2[ptr] == '1') break;
    }
    if (ptr != -1) {
        v2[ptr] = '0';
        for (auto x:v2) {
            cout << x;
        }
        cout << endl;
    } else {
        cout << "-" << endl;
    }


    ptr = v.size() - 1;
    OK = true;
    if (v[ptr] == '0') OK = false;
    while (ptr >= 0 && OK) {
        v[ptr] = '0';
        ptr--;
        if (v[ptr] == '0') break;
    }
    if (ptr > -1 ) {
        v[ptr] = '1';
        for (auto x:v) {
            cout << x;
        }
        cout << endl;
    } else {
        cout << '-' << endl;
    }
    return 0;
}