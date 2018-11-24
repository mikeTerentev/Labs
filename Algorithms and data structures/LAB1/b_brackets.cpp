#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    string s;
    cin >> s;
    vector<char> a(0);
    for (char x:s) {
        if (x == '(' || x == '['||x=='{') {
            a.push_back(x);
            continue;
        } else {
            if (a.empty()) {
                cout << "NO";
                return 0;
            }
        }
        char last = a.back();
        if ((x == ')' && last == '(') || (x == ']' && last == '[')||(x == '}' && last == '{')) {
            a.pop_back();
        } else {
            cout << "NO";
            return 0;
        }
    }
    if (a.size() == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}