#include <iostream>
#include <vector>

using namespace std;

struct Node {
public :
    long long val = 0, min = LONG_LONG_MAX, add = 0;
    int l;
    int r;
    bool isSet = false;
    Node *lChild = nullptr;
    Node *rChild = nullptr;
};

void propagate(Node &node) {
    if (node.l == NULL) {
        node.add = 0;
        node.isSet = false;
    } else {
        if (node.isSet) {

            node.isSet = false;

            node.lChild->add = 0;
            node.rChild->add = 0;

            node.rChild->val = node.val;
            node.lChild->val = node.val;

            node.lChild->isSet = true;
            node.rChild->isSet = true;
        } else if (node.add != 0) {
            if (!node.lChild->isSet) {
                node.lChild->add += node.add;
            }
            if (!node.rChild->isSet) {
                node.rChild->add += node.add;
            }
            node.lChild->val += node.add;
            node.rChild->val += node.add;

            node.add = 0;
        }
    }

}

long long findMin(Node &node, int l, int r) {
    if (l > node.r || node.l > r) return INT32_MAX;
    if (node.l >= l && node.r <= r) return node.min;
    propagate(node);
    return min(findMin(*node.lChild, l, r), findMin(*node.rChild, l, r));
}

void set(Node &node, int l, int r, long long x) {
    if (node.l > r || l > node.r) return;
    if (node.l >= l && node.r <= r && node.isSet) {
        node.val = x;
        node.min = x;
        node.add = 0;
        node.isSet = true;
        return;
    }
    propagate(node);
    set(*node.lChild, l, r, x);
    set(*node.rChild, l, r, x);
    node.min = min(node.lChild->min, node.rChild->min);
}

void change(Node &node, int l, int r, long long x) {
    if (node.l > r || l > node.r) return;
    if (node.l >= l && node.r <= r && node.isSet) {
        node.add += x;
        node.min += x;
        return;
    }
    propagate(node);
    change(*node.lChild, l, r, x);
    change(*node.rChild, l, r, x);
    node.min = min(node.lChild->min, node.rChild->min);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("rmq2.in", "r", stdin);
    freopen("rmq2.out", "w", stdout);
    long long n;
    string call;
    cin >> n;
    vector<long long> a(n);
    for (auto i = 0; i < n; i++) cin >> a[i];

    //tree generation
    int pow = 0;
    long long tmp = n;
    while (tmp > 0) {
        tmp >>= 1;
        pow++;
    }
    long long listSize = 1 << (pow);
    vector<Node> tr(static_cast<unsigned long>(2 * listSize - 1));
    for (auto i = 0; i < listSize; i++) {
        if (i < a.size()) {
            tr[listSize - 1 + i].val = a[i];
            tr[listSize - 1 + i].min = a[i];
        }
        tr[listSize - 1 + i].isSet = true;
        tr[listSize - 1 + i].l = i;
        tr[listSize - 1 + i].r = i;
    }

    for (auto i = listSize - 2; i > -1; i--) {
        tr[i].min = min(tr[2 * i + 1].min, tr[2 * i + 2].min);
        tr[i].l = tr[2 * i + 1].l;
        tr[i].r = tr[2 * i + 2].r;
        tr[i].lChild = &tr[2 * i + 1];
        tr[i].rChild = &tr[2 * i + 2];
    }
    //end of tree generation
    int i, j, x;
    while (cin >> call) {
        if (call == "set") {

            cin >> i >> j >> x;
            set(tr[0], i - 1, j - 1, x);
        } else if (call == "add") {
            cin >> i >> j >> x;
            change(tr[0], i - 1, j - 1, x);
        } else {
            long long r = LONG_LONG_MAX;
            cin >> i >> j;
            cout << findMin(tr[0], i - 1, j - 1) << endl;
        }

    }
    return 0;
}

