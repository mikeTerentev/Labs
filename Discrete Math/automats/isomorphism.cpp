//
// Created by Михаил Терентьев on 06/05/2018.
//

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int const N = 100000;
map<char, int> next_map[N], next_map2[N];;
bool isTerminal[N], isTaken[N], isTerminal2[N], isTaken2[N];

void isIzomorphik(int node, int node2) {
    isTaken[node] = true;
    isTaken2[node2] = isTaken[node];
    if (isTerminal[node] == isTerminal2[node2]) {
        for (auto c = 'a'; c <= 'z'; ++c) {
            if (!(isTaken[next_map[node][c]] != isTaken2[next_map2[node2][c]] && next_map[node].count(c)) &&
                next_map[node].count(c) == next_map2[node2].count(c)) {
                if (!isTaken[next_map[node][c]] && next_map[node].count(c))
                    isIzomorphik(next_map[node][c], next_map2[node2][c]);
            } else {
                cout << "NO" << endl;
                exit(0);
            }

        }
    } else {
        cout << "NO" << endl;
        exit(0);
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("isomorphism.in", "r", stdin);
    freopen("isomorphism.out", "w", stdout);

    int n, m, k, v, nn, mm, kk, a2, b2;
    char c2;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> v;
        --v;
        isTerminal[v] = true;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        --a, --b;
        next_map[a][c] = b;
    }
    cin >> nn >> mm >> kk;
    for (int i = 0; i < kk; ++i) {
        cin >> v;
        --v;
        isTerminal2[v] = true;
    }
    for (int i = 0; i < mm; ++i) {
        cin >> a2 >> b2 >> c2;
        --a2, --b2;
        next_map2[a2][c2] = b2;
    }

    if (n == nn && m == mm && k == kk) {
        isIzomorphik(0, 0);
        cout << "YES" << endl;
        return 0;
    } else {
        cout << "NO" << endl;
        return 0;
    }
}