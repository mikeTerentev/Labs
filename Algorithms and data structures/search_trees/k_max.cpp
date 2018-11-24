#include <iostream>
#include <random>
#include <algorithm>

#define p second
#define k first
using namespace std;

class CartesianTree {

private:

    struct Node {
        explicit Node(int key) : l(nullptr), r(nullptr), count(0), priority(rand()), key(key), prexSum(0) {};

        Node(int key, Node *left, Node *right) : key(key), priority(rand()), count(0), l(left), r(right), prexSum(0) {};

        Node(int key, int priority) : l(nullptr), r(nullptr), priority(priority), count(0), key(key), prexSum(0) {};


        int key, priority, count;
        long long prexSum;
        Node *l, *r;

    };

    Node *root{};

    long long sum(Node *node) {
        return node ? node->prexSum : 0;
    }

    void updateNode(Node *node) {
        if (!node) {
            return;
        } else {
            node->prexSum = sum(node->l) + sum(node->r) + node->key;
            node->count = count(node->l) + count(node->r) + 1;
        }
    }

    void split(Node *node, int key, Node *&rleft, Node *&rright) {
        if (node != nullptr) {
            if (key >= node->key) {
                split(node->r, key, node->r, rright);
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

    int get_key(Node *tree, int position) {
        if (position < count(tree->l)) {
            return get_key(tree->l, position);
        } else if (position == count(tree->l)) {
            return tree->key;
        } else {
            return get_key(tree->r, position - (count(tree->l) + 1));
        }
    }

public:

    CartesianTree() : root(nullptr) {};

    int getSize() {
        return count(root);
    }

    int count(Node *node) {
        return !node ? 0 : node->count;
    }

    explicit CartesianTree(vector<pair<int, int>> values) {
        sort(values.begin(), values.end());
        vector<Node *> stack;
        Node *left_subtree;
        for (auto value : values) {
            auto *cur_node = new Node(value.k, value.p);
            left_subtree = nullptr;

            while (!stack.empty() &&
                   stack[stack.size() - 1]->priority > value.p) {
                left_subtree = stack[stack.size() - 1];
                stack.pop_back();
            }

            if (!stack.empty()) {
                cur_node->l = stack[stack.size() - 1]->r;
                stack[stack.size() - 1]->r = cur_node;
            } else {
                root = cur_node;
                root->l = left_subtree;
            }
            stack.push_back(cur_node);
        }
    }

    void insert(int key) {
        Node *left;
        Node *mid;
        Node *right;
        split(root, key, left, right);
        split(left, key - 1, left, mid);
        merge(left, left, new Node(key));
        merge(root, left, right);
    }

    void remove(int key) {
        Node *left;
        Node *mid;
        Node *right;
        split(root, key, left, right);
        split(left, key - 1, left, mid);
        merge(root, left, right);
    }

    int get_key(int key) {
        return get_key(root, key);
    }
};

int main() {
    CartesianTree tree;
    int n, v;
    cin >> n;

    string line;

    for (int i = 0; i < n; i++) {
        std::cin >> line >> v;
        if (line == "-1") {
            tree.remove(v);
        } else if (line == "0") {
            cout << tree.get_key(tree.getSize() - v) << endl;
        } else {
            tree.insert(v);
        }
    }

    return 0;

}