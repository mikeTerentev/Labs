#include <iostream>
#include <vector>
#include <set>

#define  weight second
#define  to first
using namespace std;

int const INF = 10000000;


int main() {
    int n, m;
    vector<set<pair<int, int>>> g;
    
    set<pair<int, int>> d_set;
    vector<int> d;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g.resize(n);
    d.resize(n, INF);
    d[0] = 0;
    d_set.insert({0, 0});
    for (int i = 0; i < m; ++i) {
        int st, fin, w;
        cin >> st >> fin >> w;
        g[st - 1].insert({fin - 1, w});
        g[fin - 1].insert({st - 1, w});
    }
    for (int i = 0; i < n; i++) {
        int nextVertex;
        if (d_set.empty()) {
            break;
        }
        nextVertex = d_set.begin()->second;
        d_set.erase(d_set.begin());
        for (auto e: g[nextVertex]) {
            if (d[nextVertex] + e.weight < d[e.to]) {
                d[e.to] = d[nextVertex] + e.weight;
                d_set.insert({d[e.to], e.to});
            }
        }
    }
    for (auto x:d) { cout << x << " "; };
    return 0;
}
