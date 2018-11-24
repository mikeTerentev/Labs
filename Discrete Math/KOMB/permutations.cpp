#include <iostream>
#include <vector>

using namespace std;

void gen(vector<int> &a, bool *visit, int p, int &k) {
    if (p == a.size()) {
        cout<<k<<": ";
        for (int i = 0; i < a.size(); i++) {
            cout << a[i]<<" ";
        }
        cout << endl;
        k++;
        return;
    }
    for (int i = 0; i < a.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            a[p] = i + 1;
            gen(a, visit, p + 1, k);
            visit[i] = false;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("permutations.in", "r", stdin);
    freopen("permutations.out", "w", stdout);
    int n, m;
    int k = 0;
    int max;
    cin >> n>>max;
    bool visit[n];
    vector<int> a(n);
    for (int p = 0; p < a.size(); p++) {
        max *= p + 1;
        a[p] = p + 1;
        visit[p] = false;
    }
    for (int p = 0; p < a.size(); p++) {
        gen(a, visit, p, k);
        if (k == max) return 0;
    }
    return 0;
}