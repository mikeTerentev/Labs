#include <iostream>
#include <vector>

using namespace std;

struct Node {
public :
    long long sum = 0;
    long long l;
    long long r;
    Node *lChild = nullptr;
    Node *rChild = nullptr;
};

long long sum(Node &node, long long l, long long r) {
    if (l > node.r || node.l > r) return 0;
    if (node.l >= l && node.r <= r) return node.sum;
    return sum(*node.lChild, l, r) + sum(*node.rChild, l, r);
}

/*
void set(Node &node, long long i, long long x) {
    node.sum += x;
    if (node.lChild != nullptr && node.rChild != nullptr) {
        if (node.l > i || node.r < i) return;
        if (node.rChild->l > i) {
            set(*node.lChild, i, x);
        } else {
            set(*node.rChild, i, x);
        }
    }

}*/
void set(Node &node, long long i, long long x) {
    if (node.r == node.l) {
        node.sum = x;
        return;
    }
    if (i <= node.lChild->r && i >= node.lChild->l) set(*node.lChild, i, x);
    if (i <= node.rChild->r && i >= node.rChild->l) set(*node.rChild, i, x);
    node.sum = node.lChild->sum + node.rChild->sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("rsq.in", "r", stdin);
    freopen("rsq.out", "w", stdout);
    long long n;
    string call;
    cin >> n;
    vector<long long> a(n);
    for (auto i = 0; i < n; i++) cin >> a[i];

    //tree generation
    int pow = 0;
    int tmp = n;
    while (tmp > 0) {
        tmp >>= 1;
        pow++;
    }
    long long listSize = 1 << (pow);
    vector<Node> tr(static_cast<unsigned long>(2 * listSize - 1));
    for (auto i = 0; i < listSize; i++) {
        if (i < a.size()) tr[listSize - 1 + i].sum = a[i];
        tr[listSize - 1 + i].l = i;
        tr[listSize - 1 + i].r = i;
    }

    for (auto i = listSize - 2; i > -1; i--) {
        tr[i].sum = tr[2 * i + 1].sum + tr[2 * i + 2].sum;
        tr[i].l = tr[2 * i + 1].l;
        tr[i].r = tr[2 * i + 2].r;
        tr[i].lChild = &tr[2 * i + 1];
        tr[i].rChild = &tr[2 * i + 2];
    }
    //end of tree generation

    while (cin >> call) {
        if (call == "sum") {
            long long i, j;
            cin >> i >> j;
            cout << sum(tr[0], i - 1, j - 1) << endl;
        } else {
            long long x;
            long long i;
            cin >> i >> x;
            //  set(tr[0], i - 1, x - tr[listSize - 1 + i - 1].sum);
            set(tr[0], i - 1, x);
        }

    }
    return 0;
}

