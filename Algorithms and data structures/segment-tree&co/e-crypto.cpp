#include <iostream>
#include <vector>

using namespace std;
int module;
struct Node {
    long long ff = 1, fs = 0, sf = 0, ss = 1;
    int l, r;
    Node *lChild = nullptr;
    Node *rChild = nullptr;
};

Node multiply(Node &ml, Node &mr) {
    Node res;
    res.ff = (ml.ff * mr.ff + ml.fs * mr.sf) % module;
    res.fs = (ml.ff * mr.fs + ml.fs * mr.ss) % module;
    res.sf = (ml.sf * mr.ff + ml.ss * mr.sf) % module;
    res.ss = (ml.sf * mr.fs + ml.ss * mr.ss) % module;
    res.rChild = &mr;
    res.lChild = &ml;
    return res;
}

Node find(Node &tr, int &l, int &r, Node &netr) {
    if (l > tr.r || tr.l > r) {
        return netr;
    }
    if (tr.l >= l && tr.r <= r) {
        return tr;
    }
    Node leftResult = find(*tr.lChild, l, r, netr);
    Node rightResult = find(*tr.rChild, l, r, netr);

    return multiply(leftResult, rightResult);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crypto.in", "r", stdin);
    freopen("crypto.out", "w", stdout);
    int n, m, l, r;
    cin >> module >> n >> m;


    //tree generation
    int pow = 0;
    int tmp = n;
    while (tmp > 0) {
        tmp >>= 1;
        pow++;
    }
    int listSize = 1 << (pow);
    vector<Node> tr(static_cast<unsigned long>(2 * listSize ));
    for (auto i = 0; i < n; i++) {
        cin >> tr[listSize - 1 + i].ff >> tr[listSize - 1 + i].fs >> tr[listSize - 1 + i].sf >> tr[listSize - 1 + i].ss;

        tr[listSize - 1 + i].l = i;
        tr[listSize - 1 + i].r = i;
    }
    for (auto i = n; i < listSize; i++) {
        tr[listSize - 1 + i].l = i;
        tr[listSize - 1 + i].r = i;
    }
    for (auto i = listSize - 2; i > -1; i--) {
        tr[i] = multiply(tr[2 * i + 1], tr[2 * i + 2]);
        tr[i].l = tr[2 * i + 1].l;
        tr[i].r = tr[2 * i + 2].r;
    }
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        Node c = find(tr[0], --l, --r, tr[2 * listSize - 1]);
        cout << c.ff << " " << c.fs << "\n" << c.sf << " " << c.ss << "\n";
    }
}