#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    vector<long long> rank(0);
    long long res = 0, n;
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
    cin >> n;
    rank.reserve(n + 3);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        rank.push_back(x);
    }
    sort(rank.rbegin(), rank.rend());
    for (int i = n - 2; i >= 0; i--) {
        res += rank[i] + rank[i + 1];
        rank[i] = rank[i] + rank[i + 1];
        rank.pop_back();
        sort(rank.rbegin(), rank.rend());
    }
    cout << res;
    return 0;
}