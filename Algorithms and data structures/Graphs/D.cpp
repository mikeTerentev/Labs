#include<iostream>
#include <vector>
#include <stack>

using namespace std;


int n, m;
vector<bool> used(0);
vector<int> ans(0);
vector<int> ret(0);
vector<int> tin(0);
vector<int> colors(0);
int timer = -1;
int max_color = 0;
void dfs(int vertex, int pr,vector<vector<pair<int, int>>>& g) {
    timer++;
    tin[vertex] = timer;
    ret[vertex] = timer;
    used[vertex] = true;
    for (int i = 0; i < g[vertex].size(); ++i) {
        auto next = g[vertex][i];
        if (next.first == pr) continue;
        if (used[next.first]) {
            ret[vertex] = min(ret[vertex], tin[next.first]);
        } else {
            dfs(next.first, vertex,g);
            ret[vertex] = min(ret[vertex], ret[next.first]);
            if (ret[next.first] > tin[vertex]) {
                int cheker = 0;
                for (int j = 0; j < g[vertex].size(); ++j) {
                    if (g[vertex][i] == g[vertex][j]) {
                        cheker++;
                    }
                }
                if (cheker == 1) {
                    g[vertex][i].second = -1;
                    for (auto& x : g[next.first])
                        if (x.first == vertex)
                            x.second = -1;
                }
            }
        }
    }
}

void paint(int vertex, int color,vector<vector<pair<int, int>>>& g) {
    colors[vertex] = color;
    for (auto next : g[vertex]) {
        if (next.second==-1) continue;

        if (!colors[next.first]) {
            paint(next.first, color,g);
        }
    }
}

int main() {
    int st, fin;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    tin.resize(n);
    ret.resize(n);
    used.resize(n, 0);
    for (int i = 0; i < m; ++i) {
        cin >> st >> fin;
        g[st - 1].emplace_back(fin - 1, 1);
        g[fin - 1].emplace_back(st - 1, 1);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, -1,g);
        }
    }
    colors.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!colors[i]) {
            paint(i, ++max_color,g);
        }
    }
    cout << max_color << endl;
    for (auto x : colors) cout << x << " ";
    return 0;
}