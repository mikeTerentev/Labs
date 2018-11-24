#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main() {
    vector<long> cost;
    cin.tie();
    cout.tie();
    vector<vector<pair<long, long> >> info(500000);
    freopen("dwarf.in", "r", stdin);
    freopen("dwarf.out", "w", stdout);
    long n, m, i, j, a, x, y;
    cin >> n >> m;
    cost.resize(n);
    set<pair<int, int> > s;
    for (i = 0; i < n; ++i) {
        cin >> cost[i];
        s.insert({cost[i], i});
    }
    
    for (i = 0; i < m; i++) {
        cin >> a >> x >> y;
        info[--x].emplace_back(--y, --a);
        info[y].emplace_back(x, a);
    }
    
    while (!s.empty()) {
        long vertex = s.begin()->second;
        s.erase(s.begin());
        for (auto &item :info[vertex]) {
            long secItem = item.first, newItem = item.second;
            if (cost[secItem] + cost[vertex] < cost[newItem]) {
                s.erase({cost[newItem], newItem});
                cost[newItem] = cost[vertex] + cost[secItem];
                s.insert({cost[newItem], newItem});
            }
        }
    }
    cout << cost[0];
    return 0;
}
