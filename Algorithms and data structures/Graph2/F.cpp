
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int64_t st, fin, weights;
vector<int64_t> dist[3];
vector<int> loc(3);
int n, m;
int64_t const INF = numeric_limits<int64_t>::max();
int64_t perm[6][3] = {{0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}};
struct edge {
    int to, weight;
    
    edge(int to, int weight) : to(to), weight(weight) {}
};

int64_t res = INF;
vector<vector<edge>> edges;


vector<int64_t> findWays(int start) {
    vector<int64_t> cost(static_cast<unsigned long>(n), INF);
    set<pair<int64_t, int >> s;
    cost[start] = 0;
    for (int i = 0; i < n; i++) {
        s.emplace(cost[i], i);
    }
    for (int i = 0; i < n; i++) {
        int64_t next = s.begin()->second;
        int64_t cur = s.begin()->first;
        s.erase(s.begin());
        if (cost[next] == numeric_limits<int64_t>::max()) {
            break;
        }
        for (auto const &edge : edges[next])
            if (cost[next] < INF &&
                cost[next] + edge.weight < cost[edge.to]) {
                s.erase({cost[edge.to], edge.to});
                cost[edge.to] = cost[next] + edge.weight;
                s.emplace(cost[edge.to], edge.to);
            }
    }
    return cost;
}

int main() {
    cin >> n >> m;
    edges.resize(static_cast<unsigned long>(n));
    for (int64_t i = 0; i < m; i++) {
        cin >> st >> fin >> weights;
        edges[--st].emplace_back(--fin, weights);
        edges[fin].emplace_back(st, weights);
    }
    cin >> loc[0] >> loc[1] >> loc[2];
    for_each(loc.begin(), loc.end(), [](int &n) { --n; });
    dist[0] = findWays(loc[0]), dist[1] = findWays(loc[1]), dist[2] = findWays(loc[2]);
    int64_t f, s;
    for (auto &curPerm : perm) {
        f = dist[curPerm[0]][loc[curPerm[1]]], s = dist[curPerm[1]][loc[curPerm[2]]];
        if (f != INF && s != INF)
            if (f + s < res)
                res = f + s;
    }
    cout << (res == INF ? -1 : res);
}
