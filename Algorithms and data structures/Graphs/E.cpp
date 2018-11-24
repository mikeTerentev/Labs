#include<iostream>
#include <vector>

using namespace std;
int maxColor = 0, n, m;
vector<vector<pair<int, int>>> g;
vector<int> color, tin, ret, used;
int timmer=-1;
void dfs(int vertex, int parent) {
    ret[vertex] = tin[vertex] = ++timmer;
    used[vertex] = true;
    for (auto next : g[vertex]) {
        if (next.first == parent) {
            continue;
        }
        if (used[next.first]) {
            ret[vertex] = min(ret[vertex], tin[next.first]);
        } else {
            dfs(next.first, vertex);
            ret[vertex] = min(ret[vertex], ret[next.first]);
        }
    }
}



void paint(int vertex, int curColor) {
    used[vertex] = true;
    for (auto next : g[vertex]) {
        if (used[next.first]) {
            if (color[next.second] == 0) {
                color[next.second] = curColor;
            }
        } else {
            if (ret[next.first] >= tin[vertex]) {
                color[next.second] = ++maxColor;
                paint(next.first, maxColor);
            } else {
                color[next.second] = curColor;
                paint(next.first, curColor);
            }
        }
    }
}


int main() {
    cin >> n >> m;

    int st, fin;
    used.resize(n, 0);
    color.resize(m, 0);
    tin.resize(n);
    ret.resize(n);
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        cin >> st >> fin;
        g[st-1].emplace_back(fin-1, i);
        g[fin-1].emplace_back(st-1, i);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, -1);
        }
    }
    used.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            paint(i, 0);
        }
    }

    cout << maxColor << endl;
    for (auto x : color) {
        cout << x << " ";
    }
    return 0;
}