#include <ostream>
#include <iostream>

using namespace std;

const int MAXN = 1000003;

const int NETUAL = static_cast<const int>(1e9);
const int OUTLINE = -1;

struct node {
    int l, r, maxima, place, new_val;
    bool isChanged;

    node(int l, int r, int key, int index, bool set, int set_value) {
        this->place = index;
        this->isChanged = set;
        this->new_val = set_value;
        this->l = l;
        this->r = r;
        this->maxima = key;
    };

    node() = default;
};

node tree[MAXN * 5];

void build(int node, int cur_l, int cur_r) {
    tree[node].r = cur_r+1;
    tree[node].l = cur_l;
    int middle = cur_l + ((cur_r - cur_l) >> 1);
    if (cur_l == cur_r) {
        tree[node].maxima = 0;
        tree[node].place = cur_l;
        return;
    }
    build(2 * node + 2, middle + 1, cur_r);
    build(2 * node + 1, cur_l, middle);
    tree[node].place = tree[2 * node + (tree[2 * node + 1].maxima <= tree[2 * node + 2].maxima ? 1 : 2)].place;
    tree[node].maxima = tree[2 * node + (tree[2 * node + 1].maxima <= tree[2 * node + 2].maxima ? 1 : 2)].maxima;
}

void propagate(int v) {
    if (tree[v].isChanged) {
        if (tree[v].l != tree[v].r) {
            tree[2 * v + 1].isChanged = true;
            tree[2 * v + 2].isChanged = true;
            tree[2 * v + 1].new_val = max(tree[2 * v + 1].new_val, tree[v].new_val);
            tree[2 * v + 2].new_val = max(tree[2 * v + 2].new_val, tree[v].new_val);
        }
        tree[v].isChanged = false;
        tree[v].maxima = max(tree[v].new_val, tree[v].maxima);
    }
}

void defend(int node, int l, int r, int height) {
    propagate(node);
    if (r >= tree[node].l && tree[node].r >= l) {
        if (l <= tree[node].l && tree[node].r <= r) {
            tree[node].isChanged = true;
            tree[node].new_val = height;
            propagate(node);
            return;
        }
        defend(2 * node + 2, l, r, height);
        defend(2 * node + 1, l, r, height);
        tree[node].place = tree[2 * node + (tree[2 * node + 1].maxima > tree[2 * node + 2].maxima ? 2 : 1)].place;
        tree[node].maxima = tree[2 * node + (tree[2 * node + 1].maxima > tree[2 * node + 2].maxima ? 2 : 1)].maxima;
    }
}


pair<int, int> attack(int node, int l, int r) {
    propagate(node);
    if (r >= tree[node].l && tree[node].r >= l) {
        if (l > tree[node].l || tree[node].r > r) {
            auto cur_r = attack(2 * node + 2, l, r);
            auto cur_l = attack(2 * node + 1, l, r);
            return cur_l.first <= cur_r.first ? cur_l : cur_r;
        } else {
            return {tree[node].maxima, tree[node].place};
        }
    } else {
        return {NETUAL, OUTLINE};
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    int n, m, l, r, x;
    cin >> n >> m;
    build(0, 0, n - 1);
    pair<int, int> res;
    for (size_t i = 0; i < m; ++i) {
        cin >> line;
        if (line == "attack") {
            cin >> l >> r;
            res = attack(0, --l, --r);
            cout << res.first << " " << ++res.second << endl;

        } else {
            cin >> l >> r >> x;
            defend(0, --l, --r, x);

        }

    }


    return 0;

}