#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include<map>

using namespace std;

struct Node {
    char val;
    int nxt;
};

const int N = 110;
const long long M = 1000000007;
int n, m, k, l, dps[N * N][N * N];
vector<Node> nodes[N], wayMap[N * N];
bool isTermnal[N], isTermnalxx[N * N];

long long calc(int node, int l) {
    if (dps[node][l] != -1) {
        return dps[node][l];
    }
    if (l == 0) {
        dps[node][l] = isTermnalxx[node] ? 1 : 0;
        return dps[node][l];
    }
    dps[node][l] = 0;
    for (auto i = 0; i < wayMap[node].size(); ++i)
        dps[node][l] = (dps[node][l] + calc(wayMap[node][i].nxt, l - 1)) % M;
    return dps[node][l];
}


int main() {
    set<set<int> > set_of_lib;
    map<set<int>, int> number;
    queue<set<int> > q;
    int a, b;
    char c;
    //
    int n_from, n_to,counter = 0;;
    set<int> stack;
    freopen("problem5.in", "r", stdin);
    freopen("problem5.out", "w", stdout);
    cin >> n >> m >> k >> l;
    //
    for (int i = 0; i < N; ++i) {
        isTermnal[i] = false;
    }
    for (int i = 0; i < N * N; ++i) {
        isTermnalxx[i] = false;
        isTermnal[i] = isTermnalxx[i];
        for (int k = 0; k <= l; k++) dps[i][k] = -1;
    }
    //
    for (int i = 0; i < k; ++i) {

        cin >> a;
        isTermnal[a - 1] = true;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a;
        --b;
        nodes[a].push_back({c, b});
    }

    stack.insert(0);
    q.push(stack);
    set_of_lib.insert(stack);
    number[stack] = counter;
    ++counter;
    if (isTermnal[0]) isTermnalxx[0] = true;
    while (!q.empty()) {
        set<int> vec = q.front();
        q.pop();
        for (char letter = 'a'; letter <= 'z'; ++letter) {
            set<int> nextLib;
            for (auto node: vec)
                for (int j = 0; j < nodes[node].size(); ++j)
                    if (nodes[node][j].val == letter)
                        nextLib.insert(nodes[node][j].nxt);

            if (nextLib.empty()) continue;
            if (set_of_lib.count(nextLib) != 0) {}
            else {
                number[nextLib] = counter;
                set_of_lib.insert(nextLib);
                q.push(nextLib);
                for (auto v: nextLib) {
                    if (!isTermnal[v]) continue;
                    isTermnalxx[counter] = true;
                    break;
                }
                ++counter;
            }
            wayMap[number[vec]].push_back({letter, number[nextLib]});
        }
    }
    //

    cout << calc(0, l) << endl;

    return 0;
}