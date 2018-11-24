#include <iostream>
#include <random>
#include <algorithm>
#include <unordered_map>

#define p second
#define k first
using namespace std;
unordered_map<long long, int> hasher;

struct res {
public:
    int parent, l, r;
};

vector<res> ans;

class CartesianTree {

private:

    struct Node {
        explicit Node(int key) : l(nullptr), r(nullptr), priority(rand()), key(key), prexSum(0) {};

        Node(int key, Node *left, Node *right) : key(key), priority(rand()), l(left), r(right),
                                                 prexSum(0) {};

        Node(int key, int priority) : l(nullptr), r(nullptr), priority(priority), key(key),
                                      prexSum(0) {};


        int key, priority, index;
        long long prexSum;
        Node *l, *r;

    };

    Node *root{};


    int find_index(Node *node) {
        if (node) {
            return hasher[(node->key + 90000LL) * 150000LL + (node->priority + 40000LL)];
        } else {
            return -1;
        }
    }

    void collect_answer(Node *node, int parent) {
        if (node) {
            int n = find_index(node);
            collect_answer(node->l, n);
            //
            ans[n].parent = parent;
            ans[n].l = find_index(node->l);
            ans[n].r = find_index(node->r);
            //
            collect_answer(node->r, n);
        }
    }

public:

    CartesianTree() : root(nullptr) {};

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

    void make_answer() {
        collect_answer(root, -1);
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
  //  freopen("x","r",stdin);
    cin >> n;

    vector<pair<int, int>> values;
    int x, y;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        values.emplace_back(x, y);
        hasher[(x + 90000LL) * 150000LL + (y + 40000LL)] = i;
    }
    CartesianTree tree(values);
    ans = vector<res>(n);
    tree.make_answer();

    std::cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i].parent + 1 << " " << ans[i].l + 1 << " " << ans[i].r + 1 << endl;
    }
    return 0;
}