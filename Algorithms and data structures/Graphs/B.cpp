#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int const MAX = 50000;
int n, m;

vector<bool> used(MAX, false);
vector<int> ans(0);
vector<int> tim(0);
vector<int> ret(0);
int timmer = -1;

void dfs(int vertex, vector<vector<pair<int,int>>> &g, int pr = -1) {
    timmer++;
    ret[vertex] = timmer;
    tim[vertex] = timmer;
    used[vertex] = true;
    for (auto i = 0; i < g[vertex].size(); ++i) {
        pair<int,int> next = g[vertex][i];
        if (next.first == pr) continue;
        if (used[next.first]) {
            ret[vertex] = min(ret[vertex], tim[next.first]);
        } else {
            dfs(next.first, g, vertex);
            ret[vertex] = min(ret[vertex], ret[next.first]);
            if (ret[next.first] > tim[vertex]) {
                ans.push_back(g[vertex][i].second);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    ans.reserve(n);
    tim.reserve(m);
    ret.reserve(n);
    int st, fin;
    for (int i = 0; i < m; i++) {
        cin >> st >> fin;
        g[st - 1].emplace_back(fin - 1,i);
        g[fin - 1].emplace_back(st - 1,i);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, g);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for (auto x:ans) {
        cout << x + 1 << " ";
    }
    return 0;
}