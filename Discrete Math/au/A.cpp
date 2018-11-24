
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int N = 1000;

char first_symb;
vector<pair<int, int> > table[N];
string line;
int indx, n;

bool check(int pos, int fp) {
    if (pos == (int) line.size()) {
        return fp == -1;
    }
    if (fp == -1) {
        return false;
    }
    int cur_symbol = line[pos] - 'a';
    for (pair<int, int> cur: table[fp]) {
        if (cur.first == cur_symbol && check(pos + 1, cur.second)) {
            return true;
        }
    }
    return false;
}

bool isLetter(char f, char l) {
    return (line[indx] >= f && line[indx] <= l);
}

int main() {
    cin.tie();
    cout.tie();
    freopen("automaton.in", "r", stdin);
    freopen("automaton.out", "w", stdout);
    cin >> n >> first_symb;
    getline(cin, line);
    for (int i = 1; i <= n; ++i) {
        getline(cin, line);
        indx = 0;
        while (!isLetter('A', 'Z')) {
            indx++;
        }
        int cur = line[indx] - 'A';
        indx++;
        while (!isLetter('a', 'z')) {
            indx++;
        }
        int after = -1;
        int nxt = line[indx] - 'a';
        if (++indx < line.size()) {
            after = line[indx] - 'A';
        }
        table[cur].emplace_back(nxt, after);
    }
    int m;
    cin >> m;
    getline(cin, line);
    for (int i = 0; i < m; i++) {
        getline(cin, line);
        cout << (check(0, first_symb - 'A') ? "yes" : "no") << endl;
    }

    return 0;
}