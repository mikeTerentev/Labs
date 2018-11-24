#include <iostream>
#include<cstring>

using namespace std;

class binarySearchTree {

private:

    struct Node {

        int v;
        Node *l, *r;

        Node() = delete;

        Node(int num) : v(num), l(nullptr), r(nullptr) {};

    };

    Node *root;

    Node *findMin(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->l == nullptr) {
            return node;
        } else {
            return findMin(node->l);
        }

    }

    Node *insert(Node *node, int num) {
        if (node == nullptr) return new Node(num);

        if (num > node->v) {
            node->r = insert(node->r, num);
        } else if (num < node->v) {
            node->l = insert(node->l, num);
        }
        return node;
    }

    Node *find(Node *n, int num) {
        if (n == nullptr || n->v == num) return n;

        return find(num < n->v ? n->l : n->r, num);
    }


    Node *remove(Node *node, int value) {
        if (node == nullptr || (node->r == nullptr && node->l == nullptr && value == node->v)) {
            return nullptr;
        }

        if (value < node->v) {
            node->l = remove(node->l, value);
        } else if (value > node->v) {
            node->r = remove(node->r, value);
        } else if (node->l != nullptr && node->r != nullptr) {
            Node *next = findMin(node->r);
            node->v = next->v;
            node->r = remove(node->r, node->v);
        } else if (node->l != nullptr) {
            return node->l;
        } else {
            return node->r;
        }

        return node;
    }


public:

    binarySearchTree() : root(nullptr) {};

    bool exists(int value) {
        return find(root, value) != nullptr;
    }

    int *getNext(int value) {
        Node *cur = root, *res = nullptr;
        while (cur != nullptr) {
            if (cur->v > value) {
                res = cur;
                cur = cur->l;
            } else {
                cur = cur->r;
            }
        }

        return res == nullptr ? nullptr : &res->v;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = remove(root, value);
    }

    int *getPrev(int value) {
        Node *cur = root, *res = nullptr;
        while (cur != nullptr) {
            if (cur->v < value) {
                res = cur;
                cur = cur->r;
            } else {
                cur = cur->l;
            }
        }
        return res == nullptr ? nullptr : &res->v;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    binarySearchTree tree;
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