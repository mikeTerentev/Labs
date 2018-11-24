#include <iostream>

using namespace std;

class SplayTree {

private:

    struct Node {
        Node *p, *l, *r;
        int key;

        Node() = delete;

        Node(int key) : key(key), p(nullptr), l(nullptr), r(nullptr) {};

        Node(int key, Node *left, Node *right) : key(key), p(nullptr), l(left), r(right) {};

        bool isLeftSubTree() {
            return p != nullptr && p->l == this;
        }

        bool hasGparent() {
            return p != nullptr && p->p != nullptr;
        }
    };

    Node *root;

    void zig(Node *node) {
        Node *parent = node->p;

        if (node->hasGparent()) {
            if (parent->p->l == parent) {
                parent->p->l = node;
            } else {
                parent->p->r = node;
            }
        }
        node->p = parent->p;
        if (parent->l == node) {
            parent->l = node->r;
            if (parent->l != nullptr) {
                parent->l->p = parent;
            }
            node->r = parent;
        } else {
            parent->r = node->l;
            if (parent->r != nullptr) {
                parent->r->p = parent;
            }
            node->l = parent;
        }
        parent->p = node;
    }

    void zig_zig(Node *node) {
        zig(node->p);
        zig(node);
    }

    void zig_zag(Node *node) {
        zig(node);
        zig(node);
    }

    Node *splay(Node *node) {
        if (node->p == nullptr) {
            return node;
        }

        if (!node->hasGparent()) {
            zig(node);
            return node;
        }
        if (node->isLeftSubTree() != node->p->isLeftSubTree()) {
            zig_zag(node);
        } else {
            zig_zig(node);
        }
        return splay(node);

    }

    Node *find(Node *node, int key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key == node->key) {
            return splay(node);
        } else if (key > node->key && node->r != nullptr) {
            return find(node->r, key);
        } else if (key <= node->key && node->l != nullptr) {
            return find(node->l, key);
        }
        return splay(node);
    }

    pair<Node *, Node *> split(int key) {
        Node *right;
        Node *left;
        if (root == nullptr) {
            return {nullptr, nullptr};
        }

        root = find(root, key);
        if (key == root->key) {
            if (root->l != nullptr) {
                root->l->p = nullptr;
            }
            if (root->r != nullptr) {
                root->r->p = nullptr;
            }
            return {root->l, root->r};
        } else if (key > root->key) {
            right = root->r;
            root->r = nullptr;
            if (right != nullptr) {
                right->p = nullptr;
            }
            return {root, right};
        } else {
            left = root->l;
            root->l = nullptr;
            if (left != nullptr) {
                left->p = nullptr;
            }
            return {left, root};
        }
    }

    Node *merge(Node *left, Node *right) {
        if (right == nullptr) {
            return left;
        }
        if (left == nullptr) {
            return right;
        }

        right = find(right, left->key);
        right->l = left;
        left->p = right;
        return right;
    }

public:

    SplayTree() : root(nullptr) {};

    bool exists(int key) {
        root = find(root, key);
        return (root != nullptr && root->key == key);
    }

    void insert(int key) {
        auto spl = split(key);
        root = new Node(key, spl.first, spl.second);
        if (root->l != nullptr) {
            root->l->p = root;
        }
        if (root->r != nullptr) {
            root->r->p = root;
        }
    }

    void remove(int key) {
        auto spl = split(key);
        root = merge(spl.first, spl.second);
    }

    int *getNext(int key) {
        Node *cur = root;
        Node *res = nullptr;
        while (cur != nullptr) {
            if (cur->key > key) {
                res = cur;
                cur = cur->l;
            } else {
                cur = cur->r;
            }
        }

        return res == nullptr ? nullptr : &res->key;
    }

    void mergeTree(SplayTree *tree) {
        root = merge(root, tree->root);
    }

    int *getPrev(int key) {
        Node *cur = root;
        Node *res = nullptr;
        while (cur != nullptr) {
            if (cur->key >= key) {
                cur = cur->l;
            } else {
                res = cur;
                cur = cur->r;
            }
        }
        return res == nullptr ? nullptr : &res->key;
    }


};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    SplayTree tree;
    string cmd;
    int value;
    int *res;
    while (cin >> cmd >> value) {
        if (cmd == "insert") {
            tree.insert(value);
        } else if (cmd == "delete") {
            tree.remove(value);
        } else if (cmd == "next") {
            res = tree.getNext(value);
            if (res == nullptr) {
                cout << "none" << endl;
            } else {
                cout << *res << endl;
            }
        } else if (cmd == "exists") {
            if (tree.exists(value)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        } else if (cmd == "prev") {
            res = tree.getPrev(value);
            if (res == nullptr) {
                cout << "none" << endl;
            } else {
                cout << *res << endl;
            }
        }
    }

}