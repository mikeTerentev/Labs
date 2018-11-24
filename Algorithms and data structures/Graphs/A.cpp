#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int const MAX = 100000;
int n, m;

vector<string> used(MAX, "white");
vector<int> ans(0);

void dfs(int vertex, vector<vector<int>> &g) {
    used[vertex] = "grey";
    for (auto i = 0; i < g[vertex].size(); ++i) {
        int next = g[vertex][i];
        if (used[next]=="white")
            dfs(next, g);
        if (used[next]=="grey"){
            cout<<"-1";
            exit(0);
        }
    }
    used[vertex] = "black";
    ans.push_back(vertex);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> g(static_cast<unsigned long>(n));
    ans.reserve(n);
    int st, fin;
    for (int i = 0; i < m; i++) {
        cin >> st >> fin;
        g[st - 1].push_back(fin - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (used[i]=="white") {
            dfs(i, g);
        }
    }
    reverse(ans.begin(), ans.end());

    for (auto x:ans) {
        cout << x + 1 << " ";
    }
    return 0;
}