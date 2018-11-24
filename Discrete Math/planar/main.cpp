#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
    edge(int st, int to) : st(st), to(to) {}

    edge() = default;

    int st{}, to{};
};

vector<int> gamilton;

bool operator!=(const edge &first, const edge &sec) {
    return (gamilton[first.to] > gamilton[sec.st]
            && gamilton[first.st] < gamilton[sec.st]
            && gamilton[first.to] < gamilton[sec.to])
           || (gamilton[sec.to] > gamilton[first.st]
               && gamilton[sec.st] < gamilton[first.st]
               && gamilton[sec.to] < gamilton[first.to]);
}


int main() {
    vector<int> cx;
    vector<edge> edges;
    vector<vector<int>> g;
    int n, m, st, to, pos;
    bool isOk = true;
    cin >> n >> m;
    edges.resize(m), gamilton.resize(n), g.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> st >> to;
        edge edge(--st, --to);
        edges[i] = edge;
    }
    for (int i = 0; i < n; ++i) {
        cin >> st;
        gamilton[--st] = i;
    }
    for (int i = 0; i < m; ++i) {
        if (gamilton[edges[i].st] > gamilton[edges[i].to]) {
            swap(edges[i].st, edges[i].to);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == j) continue;
            if (edges[i] != edges[j]) {
                g[i].push_back(j);
            }
        }
    }
    cx.resize(g.size(), 0);
    for (int i = 0; i < g.size(); ++i) {
        if (cx[i] == 0) {
            queue<int> queue;
            queue.push(i);
            cx[i] = 1;
            while (!queue.empty()) {
                pos = queue.front();
                queue.pop();
                for (int j = 0; j < g[pos].size(); ++j) {
                    if (cx[g[pos][j]] != 0) {
                        isOk &= cx[g[pos][j]] != cx[pos];
                    } else {
                        queue.push(g[pos][j]);
                        cx[g[pos][j]] = -cx[pos];
                    }
                }
            }
        }
    }


    if (isOk) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << gamilton[i]  << " " << 0 << " ";
        }
        cout << endl;

        for (int i = 0; i < m; i++) {
            cout << (double)(gamilton[edges[i].st] + gamilton[edges[i].to])/2
                 << " " << cx[i] * (double)abs(gamilton[edges[i].st] - gamilton[edges[i].to])/2
                 << endl;
        }
    } else {
        cout << "NO";
    }
}