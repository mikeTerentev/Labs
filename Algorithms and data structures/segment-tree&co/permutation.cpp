

#include <algorithm>
#include <ios>
#include <iostream>

using namespace std;
struct Node {
    long long mini;
    long long maxi;
    long long v;
};
long long res;
long long maxx, minn;

Node cree[4000000];
long long p[4000010], a[4000010];

void build(long long v, long long cl, long long cr) {
    if (cl != cr) {
        long long middle = (cl + cr) >> 1;
        build(v * 2, cl, middle);
        build(v * 2 + 1, middle + 1, cr);
        cree[v].mini = min(cree[v * 2].mini, cree[v * 2 + 1].mini);
        cree[v].maxi = max(cree[v * 2].maxi, cree[v * 2 + 1].maxi);
        cree[v].v = cree[v * 2].v + cree[v * 2 + 1].v;

    } else {
        cree[v].v = a[cl] * a[cl];
        cree[v].mini = a[cl];
        cree[v].maxi = a[cl];
    }
}

void iz(long long node, long long cl, long long cr, long long l, long long r, long long val) {
    if (l <= r) {
        if (cl != l || cr != r) {

            long long middle = (cl + cr) / 2;
            iz(node * 2, cl, middle, l, min(r, middle), val);
            iz(node * 2 + 1, middle + 1, cr, max(l, middle + 1), r, val);
            cree[node].mini = min(cree[node * 2].mini, cree[node * 2 + 1].mini);
            cree[node].maxi = max(cree[node * 2].maxi, cree[node * 2 + 1].maxi);
            cree[node].v = cree[node * 2].v + cree[node * 2 + 1].v;
        } else {
            cree[node].v = val * val;
            cree[node].mini = val;
            cree[node].maxi = val;
        }
    }
}

void ans(long long node, long long cl, long long cr, long long l, long long r) {
    if (l > r) return;
    if (cl != l || cr != r) {

        long long middle = (cl + cr) / 2;
        ans(node * 2, cl, middle, l, min(middle, r));
        ans(node * 2 + 1, middle + 1, cr, max(middle + 1, l), r);
    } else {
        res += cree[node].v;
        minn = min(minn, cree[node].mini);
        maxx = max(maxx, cree[node].maxi);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    long long n, i, l, r, t, m;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);

    for (i = 1; i <= n; i++) {
        p[i] = p[i - 1] + i * i;
    }


    cin >> m;
    for (i = 1; i <= m; i++) {
        cin >> t >> l >> r;
        if (t == 1) {
            iz(1, 1, n, l, l, r);
        } else {
            res = 0;
            maxx = 0;
            minn = n + 10;

            ans(1, 1, n, l, r);
            if (maxx <= (r - l + 1) && res == p[r - l + 1] && minn == 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}