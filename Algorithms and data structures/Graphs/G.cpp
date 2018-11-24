
#include <cxxabi.h>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<bool> used;
vector<string> names;
map<string, int> numByName;
vector<vector<int>> g, gt;
vector<int> resVertex, colors, tout_order;
int n, m;

bool isColored(int &i) {
    return i != -1;
}

int fixVertex(int vertex) {
    return vertex % 2 == 0 ? ++vertex : --vertex;
}

void dfs(int vertex) {
    used[vertex] = true;
    for (auto next : g[vertex])
        if (!used[next])
            dfs(next);
    tout_order.push_back(vertex);
}

void paint(int vertex, int color) {
    colors[vertex] = color;
    for (auto next : gt[vertex])
        if (!isColored(colors[next]))
            paint(next, color);
}


int main() {
    string first, second, tmp;
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    g.resize(static_cast<unsigned long>(2 * n));
    gt.resize(static_cast<unsigned long>(2 * n));
    names.resize(n);
    used.resize(static_cast<unsigned long>(2 * n), false);
    colors.resize(static_cast<unsigned long>(2 * n), -1);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        numByName[names[i]] = i;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> first >> tmp >> second;
        int startVertex = 2 * numByName[first.substr(1)],
        finishVertex = 2 * numByName[second.substr(1)];
        if (first[0] == '-') startVertex++;
        if (second[0] == '-') finishVertex++;
        g[startVertex].push_back(finishVertex);
        g[fixVertex(finishVertex)].push_back(fixVertex(startVertex));
        gt[finishVertex].push_back(startVertex);
        gt[fixVertex(startVertex)].push_back(fixVertex(finishVertex));
    }
    
    for (int i = 0; i < 2 * n; i++)
        if (!used[i])
            dfs(i);
    
    reverse(tout_order.begin(), tout_order.end());
    int color = -1;
    for (auto next : tout_order) {
        if (colors[next] == -1) {
            color++;
            paint(next, color);
        }
    }
    for (int i = 0; i < 2 * n; i += 2) {
        if (colors[i] == colors[i + 1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < 2 * n; i += 2) {
        if (colors[i] > colors[i + 1]) {
            resVertex.push_back(i / 2);
        }
    }
    cout << resVertex.size() << endl;
    for (auto cur : resVertex) {
        cout << names[cur] << endl;
    }
    return 0;
}
