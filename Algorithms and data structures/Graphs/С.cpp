#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int const MAX = 50000;
int n, m;

vector<bool> used(MAX, false);
vector<int> ans(0);
vector<int> tim(0);
vector<int> up(0);
vector<int> isTaken(MAX, false);
int timmer = -1;

void dfs(int vertex, vector<vector<int>> &g, int pr = -1) {
    timmer++;
    tim[vertex] = up[vertex] = timmer;
    used[vertex] = true;
    int count = 0;
    for (auto i = 0; i < g[vertex].size(); ++i) {
        int next = g[vertex][i];
        if (next == pr) {
            continue;
        }
        if (used[next]) {
            up[vertex] = min(up[vertex], tim[next]);
        } else {
            dfs(next, g, vertex);
            count++;
            up[vertex] = min(up[vertex], up[next]);
            if (pr != -1 && up[next] >= tim[vertex]) {
                if(!isTaken[vertex]){
                    ans.push_back(vertex);
                    isTaken[vertex]= true;
                }
            }
        }
    }
    if (pr == -1 && count >= 2) {
        if(!isTaken[vertex]){
            ans.push_back(vertex);
            isTaken[vertex]= true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> g(n);
    ans.reserve(n);
    tim.reserve(m);
    up.reserve(n);
    int st, fin;
    for (int i = 0; i < m; i++) {
        cin >> st >> fin;
        g[st - 1].emplace_back(fin - 1);
        g[fin - 1].emplace_back(st - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, g);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x:ans) {
        cout << x + 1 << " ";
    }
    return 0;
}