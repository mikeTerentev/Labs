#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void add(list<int> &left, list<int> &right, int val) {
    right.push_back(val);
    if (left.size() < right.size()) {
        int x = right.front();
        left.push_back(x);
        right.pop_front();
    }
}

void del(list<int> &left, list<int> &right) {
    cout << left.front() << endl;
    left.pop_front();
    if (left.size() < right.size()) {
        int x = right.front();
        left.push_back(x);
        right.pop_front();
    }
}

void spravka(list<int> &left, list<int> &right, int val) {
    if (left.size() > right.size()) {
        right.push_front(val);
    } else {
        left.push_back(val);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("hospital.in", "r", stdin);
    freopen("hospital.out", "w", stdout);
    char k;
    int parts, val;
    cin >> parts;
    list<int> left, right;
    for (int i = 1; i <= parts; i++) {
        cin >> k;
        if (k == '+') {
            cin >> val;
            add(left, right, val);
        }
        if (k == '-') {
            del(left, right);
            continue;
        }
        if (k == '*') {
            cin >> val;
            spravka(left, right, val);
            continue;
        }
    }
    return 0;
}