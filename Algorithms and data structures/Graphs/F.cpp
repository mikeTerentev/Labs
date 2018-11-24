#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int> > g, gT;
vector<char> used;
vector<int> comp;
set<pair<int, int>> res;
vector<int> tout_order;

int n, m, cur_comp = 1;

void topsort(int vertex) {
    used[vertex] = true;
    for (auto &next : g[vertex]) {
        if (!used[next]) {
            topsort(next);
        }
    }
    tout_order.push_back(vertex);
}

void make_component(int vertex) {
    used[vertex] = true;
    comp[vertex] = cur_comp;
    for (auto &next : gT[vertex]) {
        if (!used[next]) {
            make_component(next);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g.resize(n);
    comp.resize(n);
    gT.resize(n);
    tout_order.resize(n);
    used.resize(n, false);
    int st, fin;
    for (int i = 0; i < m; i++) {
        cin >> st >> fin;
        g[st - 1].emplace_back(fin - 1);
        gT[fin - 1].emplace_back(st - 1);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            topsort(i);
        }
    }
    used.assign(static_cast<unsigned long>(n), false);
    reverse(tout_order.begin(), tout_order.end());
    for (int current :tout_order) {
        if (!used[current]) {
            make_component(current);
            cur_comp++;
        }
    }
    for (auto i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            int next = g[i][j];
            if (comp[i] != comp[next]) {
                res.insert({comp[i], comp[next]});
            }
        }
    }
    cout<<res.size();
    return 0;
}