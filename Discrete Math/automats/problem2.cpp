//
// Created by Михаил Терентьев on 28/04/2018.
//


#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
struct Node {
    int nxt;
    char letter;

};



int main() {
    string word;
    int n, m, k;
    vector<Node> d[101];
    bool isTerminal[101];
    set<int> cur_points;
    set<int> nexts_points;

    int a, b;
    char c;
    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);
    getline(cin, word);
    cin >> n >> m >> k;
    for (auto i = 0; i < n; ++i) isTerminal[i] = false;

    for (auto i = 0; i < k; ++i) {
        cin >> a;
        isTerminal[a - 1] = true;
    }
    for (auto i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --b, --a;
        d[a].push_back({b, c});
    }
    cur_points.insert(0);
    for (auto letter: word) {
        nexts_points.clear();
        for (auto k: cur_points)
            for (auto &i : d[k])
                if (i.letter == letter) nexts_points.insert(i.nxt);
        cur_points.clear();
        for (auto k: nexts_points) cur_points.insert(k);
    }
    for (auto k: cur_points) {
        if (isTerminal[k]) {
            cout << "Accepts";
            return 0;
        };
    }
    cout << "Rejects";
    return 0;
}