#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long n;
long const INF = 1000000000;

struct edge {
    edge(long f, long s, long weight) : st(f), fin(s), weight(weight) {}
    
    long st, fin, weight;
};

int main() {
    int m, k, s;
    vector<long> d;
    vector<long> prev;
    vector<vector<long>> res;
    vector<edge> edges;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> s;
    s--;
    for (long i = 0; i < m; ++i) {
        int st, fin, cost;
        cin >> st >> fin >> cost;
        edge x(st - 1, fin - 1, cost);
        edges.push_back(x);
    }
    res.resize(k+1, vector<long>(n,INF));
    res[0][s] = 0;
    for (long i = 1; i <= k; ++i) {
        for (auto e:edges) {
            res[i][e.fin] = min(res[i][e.fin], res[i-1][e.st] + e.weight);
        }
    }
    for_each(res[k].begin(), res[k].end(), [](long &n) {
        cout << (n  >= INF/2 ? -1 : n);
        cout << endl;
    });
    return 0;
}
