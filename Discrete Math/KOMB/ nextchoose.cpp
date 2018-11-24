#include <iostream>
#include <vector>

using namespace std;

void out(vector<int> a, int k) {
    for (int i = 0; i < k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void fall() {
    cout << -1;
    cout << endl;
}

int main() {
    int n, k;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("nextchoose.in", "r", stdin);
    freopen("nextchoose.out", "w", stdout);
    cin >> n >> k;
    int maxk = k - 1;
    int size = n;
    vector<int> c(k + 1);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }
    int tmp = n + 1;
    c[k] = tmp;
    while (c[maxk + 1] - c[maxk] <= 1 && maxk > -1) {
        maxk = maxk - 1;
    }
    if (-1 < maxk) {
        tmp = maxk + 1;
        c[maxk] += 1;
        for (int x = tmp; x < k; x++) {
            int pre = x - 1;
            c[x] = c[pre] + 1;
        }
        out(c, k);
        return 0;
    }
    fall();


    return 0;
}