
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int nxt;
    char letter;
};


int main() {
    string word;
    int n, m, k, terminale, a, b;
    vector<Node> d[100001];
    string isTerminale[100001];
    char c;
    freopen("problem1.in", "r", stdin);
    freopen("problem1.out", "w", stdout);
    getline(cin, word);
    cin >> n/*сост*/ >> m/*перех*/>> k/*доп сост*/;
    for (int i = 0; i < n; ++i) isTerminale[i] = "Rejects";

    for (int i = 0; i < k; ++i) {
        cin >> terminale;
        isTerminale[terminale - 1] = "Accepts";
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        d[--a].push_back({--b, c});
    }


    int current = 0;
    for (auto next: word) {
        bool isWay = false;
        for (auto i = 0; i < d[current].size(); ++i) {
            if (d[current][i].letter == next) {
                isWay = true;
                current = d[current][i].nxt;
                break;
            }
        }
        if (!isWay) {
            cout << "Rejects";
            return 0;
        }
    }
    cout << isTerminale[current];


    return 0;
}