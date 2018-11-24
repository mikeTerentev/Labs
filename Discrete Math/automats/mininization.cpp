#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct s {
    long long nextSym[26];
};

struct ss {
    vector<long long> nextSym[26];
};
vector<bool> isAllowed;
vector<vector<long long>> table;
long long n, m, k;

void buildReachable(long long u) {
    isAllowed[u] = true;
    for (long long v : table[u]) {
        if (isAllowed[v]) continue;
        buildReachable(v);
    }
}

int main() {
    vector<ss> maper;
    vector<s> edges;
    vector<bool> isTerminal;
    vector<vector<bool>> isColored;
    vector<long long> coxmx;
    long long compCount;
    long long a, b;
    char c;
    long long nnnn = compCount;
    freopen("minimization.in", "r", stdin);
    freopen("minimization.out", "w", stdout);

    cin >> n >> m >> k;
    n++;

    isColored.resize(static_cast<unsigned long>(n));
    table.resize(static_cast<unsigned long>(n));
    isTerminal.resize(static_cast<unsigned long>(n));
    edges.resize(static_cast<unsigned long>(n));
    isAllowed.resize(static_cast<unsigned long>(n));
    maper.resize(static_cast<unsigned long>(n));

    for (long long i = 0; i < k; i++) {
        long long term;
        cin >> term;
        isTerminal[term] = true;
    }
    for (long long i = 0; i < m; i++) {

        cin >> a >> b >> c;
        table[a].push_back(b);
        edges[a].nextSym[c - 'a'] = b;
        maper[b].nextSym[c - 'a'].push_back(a);

    }
    for (long long i = 0; i < n; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (edges[i].nextSym[c - 'a'] == 0) {
                maper[0].nextSym[c - 'a'].push_back(i);
            }
        }
    }
    for (long long i = 0; i < n; i++) {
        isColored[i].resize(static_cast<unsigned long>(n));
    }

    buildReachable(1);
    queue<pair<long long, long long>> queue;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            if (isColored[i][j] || isTerminal[i] == isTerminal[j]) continue;
            isColored[i][j] = isColored[j][i] = true;
            queue.emplace(i, j);
        }
    }
    while (!queue.empty()) {
        auto p = queue.front();
        queue.pop();
        long long z = p.first, zz = p.second;
        for (char c = 'a'; c <= 'z'; c++) {
            for (long long r : maper[z].nextSym[c - 'a']) {
                for (long long s : maper[zz].nextSym[c - 'a']) {
                    if (isColored[r][s]) continue;
                    isColored[r][s] = isColored[s][r] = true;
                    queue.emplace(r, s);
                }
            }
        }
    }
    compCount = 0;
    coxmx.assign(static_cast<unsigned long>(n), -1);
    for (long long i = 0; i < n; i++) {
        if (isColored[0][i]) continue;
        coxmx[i] = 0;
    }
    for (long long i = 1; i < n; i++) {
        if (isAllowed[i]) {
            if (coxmx[i] == -1) {
                compCount++;
                coxmx[i] = compCount;
                for (long long j = i + 1; j < n; j++) {
                    if (isColored[i][j]) continue;
                    coxmx[j] = compCount;
                }
            }
        }
    }
    vector<s> newEdges(static_cast<unsigned long>(nnnn + 1));
    for (long long i = 0; i < n; i++) {
        if (coxmx[i] != -1) {
            for (char c = 'a'; c <= 'z'; c++)
                newEdges[coxmx[i]].nextSym[c - 'a'] = coxmx[edges[i].nextSym[c - 'a']];
        }
    }
    set<pair<pair<long long, long long>, char>> nodeN;
    for (long long i = 0; i < n; i++) {
        if (coxmx[i] != -1) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (!newEdges[coxmx[i]].nextSym[c - 'a']) continue;
                nodeN.insert({{coxmx[i], newEdges[coxmx[i]].nextSym[c - 'a']}, c});
            }
        }
    }
    long long mmmm = static_cast<long long>(nodeN.size());
    set<long long> newTerminal;
    for (long long i = 0; i < n; i++) if (isTerminal[i] && coxmx[i])newTerminal.insert(coxmx[i]);
    long long kkkk = static_cast<long long>(newTerminal.size());

    cout << nnnn << ' ' << mmmm << ' ' << kkkk << endl;
    for (long long t : newTerminal) cout << t << ' ';

    cout << endl;
    for (auto &p : nodeN)
        cout << p.first.first << ' ' << p.first.second << ' ' << p.second << endl;


    return 0;
}