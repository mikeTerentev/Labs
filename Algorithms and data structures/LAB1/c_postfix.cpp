#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isNumber(char tmp) {
    return tmp >= (int) '0' && tmp <= (int) '9' ? true : false;
}

bool isOperator(char tmp) {
    return tmp == '*' || tmp == '-' || tmp == '+' || tmp == '/' ? true : false;
}

int calculate(int l1, int l2, char s) {
    if (s == '*') return l1 * l2;
    return s == '+' ? l1 + l2 : l1 - l2;
}

int main() {
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    vector<int> m(0);
    char s;
    int res;
    while (cin >> s) {
        if (s != '\0') {
            if (isNumber(s)) {
                m.push_back(s - '0');
            }
            if (isOperator(s)) {
                int l2 = m.back();
                m.pop_back();
                int l1 = m.back();
                m.pop_back();
                m.push_back(calculate(l1, l2, s));
            }
        }
    }
    cout << m[0];
    return 0;
}