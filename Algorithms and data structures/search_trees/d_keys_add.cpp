#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <iostream>

using namespace std;

class CartesianTree {

private:

    struct Node {
        Node(int value)
                : indexes(1),
                  priority(rand()),
                  hasZero(true),
                  l(nullptr),
                  r(nullptr),
                  value(value),
                  hasDigit(false) {};

        Node(int value, Node *l, Node *r)
                : indexes(1),
                  l(l),
                  r(r),
                  value(value),
                  priority(rand()),
                  hasZero(true),
                  hasDigit(false) {};

        int indexes, value, priority;
        bool hasZero, hasDigit;
        Node *l, *r;
    };

    Node *root;

    int count(Node *node) {
        return node ? node->indexes : 0;
    }

    bool has_zero(Node *node) {
        return node ? node->hasZero : false;
    }

    bool has_nonzero(Node *node) {
        return node ? node->hasDigit : false;
    }

    void update(Node *node) {
        if (!node) return;
        node->hasZero = has_zero(node->r) || has_zero(node->l) || node->value == 0;
        node->hasDigit = has_nonzero(node->r) || has_nonzero(node->l) || node->value != 0;
        node->indexes = count(node->l) + count(node->r) + 1;
    }

    void split(Node *tree, int key, Node *&lR, Node *&rR) {
        if (!tree) {
            lR = nullptr;
            rR = lR;
        } else {
            if (key <= count(tree->l)) {
                split(tree->l, key, lR, tree->l);
                rR = tree;
            } else {
                split(tree->r, key - count(tree->l) - 1, tree->r, rR);
                lR = tree;
            }
        }
        update(tree);
    }

    void merge(Node *&tree, Node *l, Node *r) {
        if (!l || !r) {
            tree = l ? l : r;
        } else {
            if (l->priority > r->priority) {
                merge(l->r, l->r, r);
                tree = l;
            } else {
                merge(r->l, l, r->l);
                tree = r;
            }
        }
        update(tree);
    }

    void coutTree(Node *node, int size) {
        if (node && size > 0) {
            coutTree(node->l, size);
            size -= count(node->l);
            if (size-- > 0) {
                std::cout << node->value << ' ';
            }
            coutTree(node->r, size);
        }
    }

    int findSize(Node *node) {
        if (has_nonzero(node)) {
            if (!has_nonzero(node->r) && node->value == 0) {
                return findSize(node->l);
            } else if (has_nonzero(node->r)) {
                return count(node->l) + 1 + findSize(node->r);
            } else {
                return count(node->l) + 1;
            }
        } else {
            return 0;
        }
    }

    void remove_lest_zero(Node *tree, Node *&res_tr) {
        if (has_zero(tree)) {
            if (has_zero(tree->l)) {
                remove_lest_zero(tree->l, tree->l);
                res_tr = tree;
            } else {
                if (tree->value == 0) {
                    merge(res_tr, tree->l, tree->r);
                } else {
                    remove_lest_zero(tree->r, tree->r);
                    res_tr = tree;
                }
            }
        }
        update(tree);
    }
public:

    CartesianTree() : root(nullptr) {};

    void insert(int value, int position) {
        Node *lR;
        Node *rR;
        split(root, position, lR, rR);
        merge(lR, lR, new Node(value));
        merge(root, lR, rR);
    }

    void insert_with_shift(int value, int position) {
        Node *lR;
        Node *rR;
        split(root, position, lR, rR);
        merge(lR, lR, new Node(value));
        remove_lest_zero(rR, rR);
        merge(root, lR, rR);
    }

    void remove(int position) {
        Node *lR;
        Node *rR;
        split(root, position, lR, rR);
        merge(lR, lR->l, lR->r);
        merge(root, lR, rR);
    }

    int get_size() {
        return findSize(root);
    }

    void coutGoodTree(int number) {
        coutTree(root, number);
        std::cout << '\n';
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    CartesianTree tree;
    int l, n, size, m;
    std::cin >> n >> m;

    for (int i = 0; i < n + m; i++) tree.insert(0, i);


    for (int i = 0; i < n; i++) {
        cin >> l;
        tree.insert_with_shift(i + 1, l - 1);
    }

    size = tree.get_size();
    cout << size << '\n';
    tree.coutGoodTree(size);

    return 0;
};