#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct Node {
    bool isTerminal, isTaken;
    int letter_map[40];
};

vector<Node> first;
vector<Node> second;
int nextF, nextS, fe, se;

bool check_eqv(int s1, int s2) {
    set<pair<int, int>> taken;
    queue<pair<int, int>> queue;
    queue.emplace(s1, s2);
    second[s2].isTaken = first[s1].isTaken;
    while (true) {
        if (queue.empty()) break;
        se = queue.front().second;
        fe = queue.front().first;
        queue.pop();
        if (first[fe].isTerminal == second[se].isTerminal) {
            for (auto letter = 'a'; letter <= 'z'; ++letter) {
                nextF = first[fe].letter_map[letter - 'a'];
                nextS = second[se].letter_map[letter - 'a'];
                if (!taken.count(make_pair(nextF, nextS))) {
                    first[nextF].isTaken = true;
                    second[nextS].isTaken = first[nextF].isTaken;
                    taken.emplace(make_pair(nextF, nextS));
                    queue.emplace(nextF, nextS);
                }
            }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m, k, a, b, term_p;
    char c;
    freopen("equivalence.in", "r", stdin);
    freopen("equivalence.out", "w", stdout);
    cin >> n >> m >> k;
    ++n;
    first.resize(n);
    for (int i = 0; i < k; ++i) {

        cin >> term_p;
        first[term_p].isTerminal = true;
    }
    for (int i = 0; i < m; ++i) {

        cin >> a >> b >> c;
        first[a].letter_map[c - 'a'] = b;
    }
    //
    cin >> n >> m >> k;
    ++n;
    second.resize(n);
    for (int i = 0; i < k; ++i) {
        cin >> term_p;
        second[term_p].isTerminal = true;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        second[a].letter_map[c - 'a'] = b;
    }


    cout << (check_eqv(1, 1) ? "YES" : "NO") << endl;

    return 0;
}