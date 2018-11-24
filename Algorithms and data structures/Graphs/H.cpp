#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int> > g, gT;
vector<char> used;
vector<int> comp;

vector<int> tout_order;

int n, m, cur_comp = 1;

void dfs(int vertex, long long mass) {
    used[vertex] = true;
    for (int next = 0; next < n; next++) {
        if (g[vertex][next] <= mass && !used[next]) {
            dfs(next, mass);
        }
    }
    tout_order.push_back(vertex);
}

void goBack(int vertex, long long mass) {
    used[vertex] = true;
    comp.push_back(vertex);
    for (int next = 0; next < n; next++) {
        if (gT[vertex][next] <= mass && !used[next]) {
            goBack(next, mass);
        }
    }
}


int main() {
    long long l = -1, r = 1000000000;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("avia.in", "r", stdin);
    freopen("avia.out", "w",stdout);
    cin >> n;
    g.resize(n, vector<int>(n));
    gT.resize(n, vector<int>(n));
    comp.resize(n);
    tout_order.resize(n);
    used.resize(n, false);
    long long st,maxxx=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> st;
            g[i][j] = st;
            gT[j][i] = st;
            maxxx=max(st,maxxx);
        }
    }
    r=maxxx;
    while (r - l > 1) {
        long long m = (l + r) >> 1;
        comp.clear();
        tout_order.clear();
        used.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i, m);
            }
        }
        used.assign(n, false);
        reverse(tout_order.begin(), tout_order.end());
        for(auto cur:tout_order){
            if (!used[cur]) {
                goBack(cur, m);
                if (comp.size() == n) {
                    r = m;
                } else {
                    l = m;
                }
                break;
            }
        }
    }
    cout << r;
    return 0;
}