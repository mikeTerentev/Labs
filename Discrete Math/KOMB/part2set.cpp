#include<iostream>
#include <vector>
#include<set>

using namespace std;

void out(vector<int> a) {
    for (auto i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
}

void find_break(int &i, vector<int> &perm) {
    while (perm[i] + 1 > perm[i + 1] && i > -1) {
        i--;
    }
}

void fall(int n) {
    for (auto i = 0; i < n; i++) {
        cout << 0 << " ";
    }
}

void find_minmax(int &j, int &n, vector<int> &perm, int &i) {
    while (j <= n - 2 && perm[j + 1] >= perm[i] + 1)
        j++;
}

void swap(vector<int> &a, int f, int s) {
    swap(a[f], a[s]);
}

void all_subsets(int n, int k, vector<int> *a) {
    for (int el : *a) {
        cout << el + 1 << ' ';
    }
    cout << '\n';

    for (int t = k; t < n; t++) {
        a->push_back(t);
        all_subsets(n, t + 1, a);
        a->pop_back();
    }
}

void all_set_partitions(int n, int k, int size, vector<set<int>> *a) {
    if (size == n) {
        for (uint i = 0; i < k; i++) {
            for (int el : (*a)[i]) {
                cout << el + 1 << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    } else {
        uint last = 0;
        for (; last < k && !(*a)[last].empty(); last++);
        if (k - last < n - size) {
            for (uint i = 0; i <= last && i < k; i++) {
                (*a)[i].insert(size++);
                all_set_partitions(n, k, size, a);
                (*a)[i].erase(--size);
            }
        } else {
            (*a)[last].insert(size++);
            all_set_partitions(n, k, size, a);
            (*a)[last].erase(--size);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("part2sets.in", "r", stdin);
    freopen("part2sets.out", "w", stdout);
    int n, k, tmp, changing_n;
    bool haveNext = false;
    cin >> n >> k;
    vector<int> perm(0);
    perm.reserve(n);
    for (int i = 0; i < 2; i++) {
        perm.push_back(i + 1);
    }
    all_set_partitions(n, k, 2, perm);
    return 0;
}