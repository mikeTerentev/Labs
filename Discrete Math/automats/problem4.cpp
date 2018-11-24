//
// Created by Михаил Терентьев on 28/04/2018.
//

//
// Created by Михаил Терентьев on 28/04/2018.
//


#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
struct Node {
    int nxt;
};
string word;
int n, m, k, next;
long long dps[101][10004];
vector<Node> d[101];
bool isTerminal[101];

int a, b, l;
char c;

long long find(int node, int len) {
    if (dps[node][len] == -1) {
        if (len != 0) {
            dps[node][len] = 0;
            for (auto &i : d[node])
                dps[node][len] = (dps[node][len] + find(i.nxt, len - 1)) % 1000000007;
            return dps[node][len];
        } else {
            dps[node][len] = isTerminal[node] ? 1 : 0;
            return dps[node][len];
        }
    } else {
        return dps[node][len];
    }
}

int main() {
    freopen("problem4.in", "r", stdin);
    freopen("problem4.out", "w", stdout);
    cin >> n >> m >> k >> l;
    for (auto i = 0; i < n; ++i) {
        isTerminal[i] = false;
        for (auto z = 0; z <= l; ++z) dps[i][z] = -1;
    }
    for (auto i = 0; i < k; ++i) {
        cin >> a;
        isTerminal[a - 1] = true;
    }
    for (auto i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --b, --a;
        d[a].push_back({b});
    }
    cout << find(0, l);
    return 0;
}