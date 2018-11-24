#include <iostream>
#include <vector>

using namespace std;

long long const INF = 8000000000000000000;

struct edge {
    long st, fin;
    long long weight;
    
    edge(long f, long t, long long w) : st(f), fin(t), weight(w) {}
};

int main() {
    long n, m, s, fin, sec;
    long long weight;
    cin >> n >> m >> s;
    --s;
    vector<edge> edges;
    edges.reserve(m);
    for (long i = 0; i < m; i++) {
        cin >> fin >> sec >> weight;
        edges.emplace_back(--fin, --sec, weight);
    }
    vector<long long> d(n, INF);
    d[s] = 0;
    for (long i = 0; i < n - 1; i++) {
        for (auto &e : edges) {
            if (d[e.st] < INF) {
                d[e.fin] = d[e.st] + e.weight < -INF ? -INF : min(d[e.fin], d[e.st] + e.weight);
            }
        }
    }
    
    
    for (long i = 0; i < n - 1; i++) {
        for (auto &edge : edges) {
            if (d[edge.st] < INF) {
                if (d[edge.st] == -INF) {
                    d[edge.fin] = -INF;
                } else if (d[edge.fin] <= -INF
                           || d[edge.st] + edge.weight < d[edge.fin]){
                    d[edge.fin] = -INF;
                }
            }
        }
    }
    
    
    for (long i = 0; i < n; i++) {
        if (d[i] >= INF) {
            cout << "*" << endl;
        } else if (d[i] <= -INF) {
            cout << "-" << endl;
        } else {
            cout << d[i] << endl;
        }
    }
}
