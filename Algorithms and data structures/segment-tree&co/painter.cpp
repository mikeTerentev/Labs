#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
struct Node {
    long l, r, lenght;
    long amount;
    bool mode, isChanged;
};
Node tree[(1 << 21) * 10];


inline void propagate(int node, int cur_l, int cur_r) {
    if (tree[node].mode) {
        if (!tree[node].isChanged) {
            tree[node].lenght = 0;
            tree[node].amount = 0;
            tree[node].l = 0;
            tree[node].r = 0;
            tree[node].isChanged = false;
            tree[node].mode = false;
            if (node < 1 << 21) {
                tree[node * 2].isChanged = false;
                tree[node * 2 + 1].isChanged = false;
                tree[node * 2].mode = true;
                tree[node * 2 + 1].mode = true;
            }
        } else {
            tree[node].lenght = cur_r - cur_l + 1;
            tree[node].amount = 1;
            tree[node].l = 1;
            tree[node].r = 1;
            tree[node].isChanged = false;
            tree[node].mode = false;
            if (node < 1 << 21) {
                tree[node * 2].mode = true;
                tree[node * 2 + 1].mode = true;
                tree[node * 2].isChanged = true;
                tree[node * 2 + 1].isChanged = true;
            }
        }
    }
}

void updateTree(bool mode, int node, int cur_left, int cur_right, int l, int r) {
    int mid = (cur_left + cur_right) >> 1;
    propagate(node, cur_left, cur_right);
    if (cur_left > r || cur_right < l) {
        return;
    }
    if (l <= cur_left && cur_right <= r) {
        tree[node].isChanged = mode;
        tree[node].mode = true;
        propagate(node, cur_left, cur_right);
        return;
    }
    updateTree(mode, node * 2, cur_left, mid, l, r);
    updateTree(mode, node * 2 + 1, mid + 1, cur_right, l, r);

    tree[node].lenght = tree[node * 2 + 1].lenght + tree[node * 2].lenght;
    tree[node].amount =
            tree[node * 2].r == 1 && tree[node * 2 + 1].l == 1 ? tree[node * 2].amount + tree[node * 2 + 1].amount - 1 :
            tree[node * 2].amount + tree[node * 2 + 1].amount;
    tree[node].r = tree[node * 2 + 1].r;
    tree[node].l = tree[node * 2].l;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("painter.in", "r", stdin);
    freopen("painter.out", "w", stdout);
    int m, l, r;
    cin >> m;
    char mode;
    while (m) {
        cin >> mode >> l >> r;
        l += 500000;
        r += l;
        --r;
        updateTree(mode == 'B', 1, 0, (1 << 21) - 1, l, r);
        cout << tree[1].amount << " " << tree[1].lenght << endl;
        --m;
    }
    return 0;
}