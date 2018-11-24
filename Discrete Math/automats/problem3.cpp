//
// Created by Михаил Терентьев on 06/05/2018.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char val;
    int nxt;
};

const int N = 100001;
const long long M = 1000000000;
int n, m, k, retries[N];
vector<Node> mapTo[N], mapFrom[N];
bool isTerminal[N], isTaken[N];
long long dps[N];
int pre_mem[N];

void go_all(int node) {
    isTaken[node] = true;
    for (auto i = 0; i < mapFrom[node].size(); ++i) {
        if (isTaken[mapFrom[node][i].nxt]) continue;
        go_all(mapFrom[node][i].nxt);
    }
}

bool can_go_around(int node) {
    int nxt;
    retries[node] = 1;
    for (auto i = 0; i < mapTo[node].size(); ++i) {
        nxt = mapTo[node][i].nxt;
        if (retries[nxt] == 1) {
            if (!isTaken[nxt]) {
                int p = pre_mem[node];
                while (p != nxt) {
                    if (!isTaken[p]) {
                        p = pre_mem[p];
                    } else return true;
                }
            } else return true;
        } else if (retries[nxt] == 0) {
            pre_mem[nxt] = node;
            if (can_go_around(nxt)) return true;
        }
    }
    retries[node] = 10000;
    return false;
}

long long make_dps(int node) {
    if (dps[node] != -10) {
        return dps[node];
    }
    dps[node] = 0;
    for (auto i = 0; i < mapFrom[node].size(); ++i) {
        dps[node] = (dps[node] + make_dps(mapFrom[node][i].nxt)) % M;
    }
    return dps[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("problem3.in", "r", stdin);
    freopen("problem3.out", "w", stdout);
    int a, b;
    char c;
    long long ans = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        isTerminal[i] = false;
        retries[i] = 0;
        dps[i] = -10;
        pre_mem[i] = static_cast<int>(dps[i]);
        isTaken[i] = false;
    }
    for (int i = 0; i < k; ++i) {
        cin >> a;
        isTerminal[a - 1] = true;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --b, --a;
        mapTo[a].push_back({c, b});
        mapFrom[b].push_back({c, a});
    }

    for (int i = 0; i < n; ++i)
        if (retries[i] == 0 && isTerminal[i])
            go_all(i);
    dps[0] = 1;
    if (can_go_around(0) != 0) {
        cout << "-1" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            if (isTerminal[i]) {
                ans = (ans + make_dps(i)) % M;
            }
        }
        cout << ans << endl;
    }

    return 0;
}