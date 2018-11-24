#include <iostream>
#include <vector>

using namespace std;

void add(vector<long long> &s, vector<long long> &m) {
    long long x;
    cin >> x;
    if (m.size() > 0) {
        long long val = m.back() + x;
        m.push_back(val);
        s.push_back(x);
    } else {
        m.push_back(x);
        s.push_back(x);
    }

}

void del(vector<long long> &s, vector<long long> &m) {
    cout << s.back() << endl;
    s.pop_back();
    m.pop_back();
}

void getMin(vector<long long> &s, vector<long long> &m) {
    int x;
    cin >> x;
    if (m.size() == x) {
        cout << m[m.size() - 1] << endl;
    } else {
        cout << m[m.size() - 1] - m[m.size() - 1 - x] << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     freopen("hemoglobin.in", "r", stdin);
    freopen("hemoglobin.out", "w", stdout);
    vector<long long> s(0);
    vector<long long> m(0);
    s.reserve(1000001);
    m.reserve(1000001);
    int n;
    char k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        switch (k) {
            case '+': {
                add(s, m);
                break;
            }
            case '-': {
                del(s, m);
                break;
            }
            case '?': {
                getMin(s, m);
                break;
            }
        }
    }

    return 0;
}