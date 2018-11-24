#include <iostream>
#include <random>
#include <algorithm>

#define p second
#define k first
using namespace std;

class CartesianTree {

private:

    struct Node {
        explicit Node(int key) : l(nullptr), r(nullptr), count(0), priority(rand()), val(key), prexSum(0) {};

        Node(int val, Node *left, Node *right) : val(val), priority(rand()), count(0), l(left), r(right), prexSum(0) {};


        int val, priority, count;
        long long prexSum;
        Node *l, *r;

    };

    Node *root{};

    int count(Node *node) {
        return !node ? 0 : node->count;
    }

    void updateNode(Node *node) {
        if (!node) {
            return;
        } else {
            node->count = count(node->l) + count(node->r) + 1;
        }
    }

    void split(Node *node, int key, Node *&rleft, Node *&rright) {
        if (node != nullptr) {
            if (key > count(node->l)) {
                split(node->r, key - count(node->l)-1, node->r, rright);
                rleft = node;
            } else {
                split(node->l, key, rleft, node->l);
                rright = node;
            }
            updateNode(node);
        } else {
            rleft = rright = nullptr;
        }
    }

    void merge(Node *&tree, Node *lPart, Node *rPart) {
        updateNode(lPart);
        updateNode(rPart);
        if (!lPart || !rPart) {
            tree = lPart ? lPart : rPart;
        } else {
            if (lPart->priority <= rPart->priority) {
                merge(rPart->l, lPart, rPart->l);
                tree = rPart;
            } else {
                merge(lPart->r, lPart->r, rPart);
                tree = lPart;
            }
        }
        updateNode(tree);
    }

    void inorder(Node *node) {
        if (node) {
            inorder(node->l);
            cout << node->val << ' ';
            inorder(node->r);
        }
    }

public:

    CartesianTree() : root(nullptr) {};

    void insert(int val, int pos) {
        Node *leftSub;
        Node *rightSub;
        split(root, pos, leftSub, rightSub);
        merge(leftSub, leftSub, new Node(val));
        merge(root, leftSub, rightSub);
    }

    void remove(int pos) {
        Node *left;
        Node *right;
        split(root, pos, left, right);
        merge(root, left->l, left->r);
        merge(root, left, right);
    }

    void move_to_begin(int strt, int endx) {
        Node *left;
        Node *cutted;
        Node *right;
        split(root, endx, left, right);
        split(left, strt, left, cutted);
        merge(left, cutted, left);
        merge(root, left, right);
    }

    void inorder() {
        inorder(root);
        std::cout << endl;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    CartesianTree tree;
    int n, m, beg, endx;
    std::cin >> n >> m;

    for (auto i = 0; i < n; i++) {
        tree.insert(i + 1, i);
    }


    for (auto i = 0; i < m; ++i) {
        std::cin >> beg >> endx;
        tree.move_to_begin(beg - 1, endx);
    }

    tree.inorder();


    return 0;

}