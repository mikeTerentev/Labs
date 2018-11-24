#include <iostream>
#include <vector>

using namespace std;

struct Node {
public :
    int v = 0;
    int l;
    int r;
    Node *lChild = nullptr;
    Node *rChild = nullptr;
};

int findMin(Node &node, int l, int r) {
    if (l > node.r || node.l > r) return INT_MAX;
    if (node.l >= l && node.r <= r) return node.v;
    return min(findMin(*node.lChild, l, r), findMin(*node.rChild, l, r));
}

int refresh(Node &node, int index, int val) {
    if (node.r == node.l) {
        node.v = val;
        return val;
    }
    if (index <= node.lChild->r) {
        return node.v = min(refresh(*node.lChild, index, val), node.rChild->v);
    } else {
        return node.v = min(node.lChild->v, refresh(*node.rChild, index, val));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("parking.in", "r", stdin);
    freopen("parking.out", "w", stdout);
    int n, m, k;
    string operation;
    cin >> n >> m;

    //tree generation
    int pow = 0;
    int tmp = n;
    while (tmp > 0) {
        tmp >>= 1;
        pow++;
    }
    int listSize = 1 << (pow);
    vector<Node> tr(static_cast<unsigned long>(2 * listSize - 1));
    for (auto i = 0; i < listSize; i++) {
        if (i < n) {
            tr[listSize - 1 + i].v = i;
        } else {
            tr[listSize - 1 + i].v = INT_MAX;
        }
        tr[listSize - 1 + i].l = i;
        tr[listSize - 1 + i].r = i;
    }

    for (auto i = listSize - 2; i > -1; i--) {
        tr[i].v = min(tr[2 * i + 1].v, tr[2 * i + 2].v);
        tr[i].l = tr[2 * i + 1].l;
        tr[i].r = tr[2 * i + 2].r;
        tr[i].lChild = &tr[2 * i + 1];
        tr[i].rChild = &tr[2 * i + 2];
    }


    for (size_t i = 0; i < m; i++) {
        cin >> operation >> k;
        k--;
        if (operation == "enter") {
            int index = findMin(tr[0], k, n);
            if (index >= n) {
                index = findMin(tr[0], 0, k - 1);
            }
            cout << index + 1 << endl;
            refresh(tr[0], index, INT_MAX);
        } else {
            refresh(tr[0], k, k);
        }
    }
    return 0;
}