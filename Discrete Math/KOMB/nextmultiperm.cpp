
#include <iostream>
#include <vector>
#include <algorithm>

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("nextmultiperm.in", "r", stdin);
    freopen("nextmultiperm.out", "w", stdout);
    int n, tmp, changing_n;
    bool haveNext = false;
    cin >> n;
    vector<int> perm(0);
    perm.reserve(n);
    while (cin >> tmp) {
        perm.push_back(tmp);
    }
    int broken = n;
    broken--;
    broken--;
    find_break(broken, perm);
    if (broken > -1) {
        int change_n = broken;
        change_n++;
        find_minmax(change_n, n, perm, broken);
        swap(perm, change_n, broken);
        reverse(perm.begin() + broken + 1, perm.end());
        out(perm);

    } else {
        fall(n);
    }
    return 0;
}