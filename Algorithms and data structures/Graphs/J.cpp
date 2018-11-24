#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int n, m;
vector<int> color;
vector<pair<int, int> > ans;
vector<pair<int, pair<int, int> > > g;

int get_vertex(int vertex) {
    if (vertex != color[vertex]) {
        return color[vertex] = get_vertex(color[vertex]);
    } else {
        return vertex;
    }
}

void connect(int fst, int scnd) {
    fst = get_vertex(fst);
    scnd = get_vertex(scnd);
    if (fst != scnd) {
        color[fst] = scnd;
    }

}

int main() {
    int b, e, w;
    long long  x = 0;
    cin >> n >> m;
    color.resize(static_cast<unsigned long>(n));
    for (int i = 0; i < m; ++i) {
        cin >> b >> e >> w;
        g.push_back({w, {b - 1, e - 1}});
    }
    int total_cost = 0;
    sort(g.begin(), g.end());
    for (int i = 0; i < n; ++i) {
        color[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int start = g[i].second.first;
        int finish = g[i].second.second;
        int cost = g[i].first;
        if (get_vertex(start) != get_vertex(finish)) {
            total_cost += cost;
            x += g[i].first;
            connect(start, finish);
        }
    }

    cout << x;
    return 0;
}