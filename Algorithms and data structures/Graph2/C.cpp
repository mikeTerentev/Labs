#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;
long n;
long const INF = 1000000000;

struct edge {
    edge(long f, long s, long weight) : st(f), fin(s), weight(weight) {}
    
    long st, fin, weight;
};

int main() {
    vector<long> d;
    vector<long> prev;
    vector<long> res;
    vector<edge> edges;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int m=0;
    for (long i = 0; i < n; ++i) {
        for (long j = 0; j < n; ++j) {
            long cost;
            cin >> cost;
            if (cost == 100000 ) {
                continue;
            }
            m++;
            edge x(i, j, cost);
            edges.push_back(x);
        }
    }
    
    d.resize(n);
    prev.resize(n, -1);
    long memory = -1;
    for (long i = 0; i < n; ++i) {
        memory = -1;
        for (long j = 0; j < m; ++j)
            if (d[edges[j].fin] > d[edges[j].st] + edges[j].weight) {
                d[edges[j].fin] = max(d[edges[j].st] + edges[j].weight, -INF);
                prev[edges[j].fin] = edges[j].st;
                memory = edges[j].fin;
            }
    }
    if (memory == -1) {
        cout << "NO";
        exit(0);
    } else {
        long start = memory;
        for (long i = 0; i < n; ++i) {
            start = prev[start];
        }
        
        for (long curVertx = start;; curVertx = prev[curVertx]) {
            res.push_back(curVertx);
            if ((curVertx == start && res.size() > 1) || prev[curVertx] == res[0]) {
                break;
            }
        }
        reverse(res.begin(), res.end());
        
        cout << "YES" << endl << res.size() << endl;
        for_each(res.begin(), res.end(), [](long &n) { cout << n + 1 << " "; });
        return 0;
    }
}

