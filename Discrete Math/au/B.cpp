#include <stdio.h>
#include <vector>
#include <iostream>
#include <set>

using namespace std;
const int N = 1001;

char first_symbol;
vector<pair<vector<int>, vector<int> > > table[N];
string line;
int n, from;
set<int> res;

void search_eps() {
    int in_size_ = static_cast<int>(res.size());
    for (int i = 0; i < 26; ++i) {
        bool isNorm = false;
        for (auto &node : table[i]) {
            bool isEps = true;
            if (!node.first.empty()) {
                isEps = false;
            }
            for (auto x: node.second) {
                if (!(res.end() == res.find(x))) continue;
                isEps = false;
            }
            if (!isEps) continue;
            isNorm = true;
        }
        if (!isNorm) continue;
        res.insert(i);
    }
    if (res.size() > in_size_) {
        search_eps();
    }
}

int main() {
    freopen("epsilon.in", "r", stdin);
    freopen("epsilon.out", "w", stdout);
    cin >> n >> first_symbol;
    getline(cin, line);
    for (int i = 1; i <= n; ++i) {
        getline(cin, line);
        vector<int> n_vec, t_vec;
        from = line[0] - 'A';
        for (int pos = 5; pos < line.size(); ++pos) {
            if (line[pos] < 'a' || line[pos] > 'z') {
                n_vec.push_back(line[pos] - 'A');
            } else {
                t_vec.push_back(line[pos] - 'a');
            }
        }
        table[from].emplace_back(t_vec, n_vec);
    }
    search_eps();
    for (int c: res) {
        cout << (char) (c + 'A') << " ";
    }
    return 0;
}