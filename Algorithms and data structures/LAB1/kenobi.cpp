#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void add(list<int> &left, list<int> &right, int val) {
    if (left.size() == 0) { left.push_back(val); }
    else {
        right.push_back(val);
    }
    while (left.size() >= 1&& right.size()>1 && (left.size() + 1 <= right.size() - 1)) {
        int x = right.front();
        left.push_back(x);
        right.pop_front();
    }
}

void del(list<int> &left, list<int> &right) {
    if (right.empty() && left.size() == 1) left.pop_back();
    if (!right.empty()) {
        right.pop_back();
        while (left.size() > right.size()) {
            int x = left.back();
            right.push_front(x);
            left.pop_back();
        }
    }
}

void mum(list<int> &left, list<int> &right) {
    if (left.size() + right.size() > 1) {
        swap(left, right);
        if (left.size() > right.size()) {
            int x = left.back();
            right.push_front(x);
            left.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("kenobi.in", "r", stdin);
    freopen("kenobi.out", "w", stdout);
    string k;
    int parts, val;
    cin >> parts;
    list<int> left, right;
    for (int i = 1; i <= parts; i++) {
        cin >> k;
        if (k == "add") {
            cin >> val;
            add(left, right, val);
        }
        if (k == "take") {
            del(left, right);

        }
        if (k == "mum!") {
            mum(left, right);
        }
        //for (int x:left) cout << x << " ";cout<<"|";
        //for (int x:right) cout << x << " ";
        //cout<<endl;
    }
    cout << left.size() + right.size() << endl;
    for (int x:left) cout << x << " ";
    for (int x:right) cout << x << " ";
    return 0;
}