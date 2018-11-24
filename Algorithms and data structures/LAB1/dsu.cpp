#include <iostream>
#include <vector>

using namespace std;
int n;

int get(vector<int>& val, int x) {
    if (val[x] != x)
        val[x] = get(val,val[x]);
    return val[x];
}

void cot(vector<int> &val, vector<int> &mi, vector<int> &ma, vector<int> &kol, int v) {
    v = get(val, v);
    cout << mi[v] << " ";
    cout << ma[v] << " ";
    cout << kol[v] << endl;
}


void unio(vector<int> &val, vector<int> &mi, vector<int> &ma, vector<int> &kol, int x, int y,vector<int> &r) {
    x = get(val, x);
    y = get(val, y);
    mi[x] = min(mi[x], mi[y]);
    ma[x] = max(ma[x], ma[y]);
    mi[y] = min(mi[x], mi[y]);
    ma[y] = max(ma[x], ma[y]);
    if (x == y) {
        return;
    }
    kol[x]+=kol[y];
    kol[y]=kol[x];
    if (r[x] == r[y]) {
        r[x]++;
    }
    r[x] < r[y] ? (val[x] = y) : (val[y] = x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("dsu.in", "r", stdin);
    freopen("dsu.out", "w", stdout);
    int x1, x2;
    string k;
    cin >> n;
    vector<int> val(n + 1);
    vector<int> ma(n + 1);
    vector<int> mi(n + 1);
    vector<int> kol(n + 1);
    vector<int> r(n + 1);
    for (int i = 1; i <= n; i++) {
        ma[i] = i;
        mi[i] = i;
        val[i] = i;
        kol[i] = 1;
        r[i]=0;
    }
    while (cin >> k) {
        if (k == "union") {
            cin >> x1 >> x2;
            unio(val, mi, ma, kol, x1, x2,r);
        }
        if (k == "get") {
            cin >> x1;
            cot(val, mi, ma, kol, x1);
        }
    }
    return 0;
}