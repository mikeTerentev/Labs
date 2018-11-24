#include <algorithm>
#include <vector>
#include <ios>
#include <iostream>

using namespace std;

long long MIN = -(1ll << 31) - 10;
long long MAX = (1ll << 31) + 10;
struct node {
    long long cur, prgted, inputTree;
    long q;
    int l, r;
};
node tree[1000002];


void makeTree(int vertex, int curr_l, int curr_r) {
    tree[vertex].prgted = MIN;
    if (curr_l == curr_r) {
        tree[vertex].cur = MIN;
        return;
    }
    int middle = (curr_l + curr_r) / 2;
    makeTree(vertex * 2, curr_l, middle);
    makeTree(vertex * 2 + 1, middle + 1, curr_r);
    tree[vertex].cur = max(tree[vertex * 2].cur, tree[vertex * 2 + 1].cur);
}

void propagate(int vertex) {
    if (tree[vertex].prgted == MIN) {
        return;
    }
    tree[vertex].cur = max(tree[vertex].cur, tree[vertex].prgted);
    tree[vertex * 2 + 1].prgted = max(tree[vertex].prgted, tree[vertex * 2 + 1].prgted);
    tree[vertex * 2].prgted = max(tree[vertex * 2].prgted, tree[vertex].prgted);
    tree[vertex].prgted = MIN;
}

long long ans(int vertex, int curr_l, int curr_r, int l, int r) {
    propagate(vertex);
    if (l > r) return MIN;
    if (curr_l == l && curr_r == r) {
        return tree[vertex].cur;
    }
    int middle = (curr_l + curr_r) >> 1;
    return max(ans(vertex * 2, curr_l, middle, l, min(middle, r)),
               ans(vertex * 2 + 1, middle + 1, curr_r, max(middle + 1, l), r));
}

void remake(int vertex, int curr_l, int curr_r) {
    if (curr_l == curr_r) {
        tree[vertex].cur = tree[curr_l].inputTree;
        return;
    }
    int middle = (curr_l + curr_r) >> 1;
    remake(vertex * 2 + 1, middle + 1, curr_r);
    remake(vertex * 2, curr_l, middle);
    tree[vertex].cur = min(tree[2 * vertex].cur, tree[2 * vertex + 1].cur);
}

long long checkAns(int vertex, int curr_l, int curr_r, int l, int r) {
    if (l > r) return MAX;
    if (curr_l == l && curr_r == r) {
        return tree[vertex].cur;
    }
    int middle = (curr_l + curr_r) >> 1;
    return min(checkAns(vertex * 2, curr_l, middle, l, min(middle, r)),
               checkAns(vertex * 2 + 1, middle + 1, curr_r, max(l, middle + 1), r));
}

void takeValue(int vertex, int curr_l, int curr_r, int l, int r, long long x) {
    propagate(vertex);
    if (l > r) return;
    if (curr_l == l && curr_r == r) {
        tree[vertex].prgted = max(tree[vertex].prgted, x);

        propagate(vertex);
        return;
    }
    int middle = (curr_l + curr_r) >> 1;
    takeValue(vertex * 2, curr_l, middle, l, min(r, middle), x);
    takeValue(vertex * 2 + 1, middle + 1, curr_r, max(l, middle + 1), r, x);
    tree[vertex].cur = max(tree[vertex * 2].cur, tree[vertex * 2 + 1].cur);
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);
    int n, m, i;
    cin >> n >> m;
    makeTree(1, 1, n);
    for (i = 1; i <= m; ++i) {
        cin >> tree[i].l >> tree[i].r >> tree[i].q;
        takeValue(1, 1, n, tree[i].l, tree[i].r, tree[i].q);
    }
    for (i = 1; i <= n; ++i) {
        tree[i].inputTree = ans(1, 1, n, i, i);
    }
    remake(1, 1, n);
    for (i = 1; i <= m; ++i) {
        if (checkAns(1, 1, n, tree[i].l, tree[i].r) != tree[i].q) {
            cout << "inconsistent";
            return 0;
        }
    }
    cout << "consistent" << endl;
    for (i = 1; i <= n; ++i) {
        cout << (tree[i].inputTree != MIN ? tree[i].inputTree : 0) << ' ';

    }
}