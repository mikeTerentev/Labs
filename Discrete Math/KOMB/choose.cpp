#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("choose.in", "r", stdin);
    freopen("choose.out", "w", stdout);
    int n, m;
    cin >> n;
    vector<int> ck(0);
    ck.reserve(n);
    cin >> m;
    for (int i = 1; i <= n; i++)
        ck.push_back(i);

    for (int i = 0; i < m; i++) {
        cout << ck[i] << " ";
    }
    cout << endl;
    bool notStop;
    while (true) {
        int curr = m;
        notStop = false;
        int startptr = curr - 1;
        for (auto i = startptr; i > -1; i--) {
            int delta = n - curr + 1;
            if (ck[i] < delta + i) {
                ck[i] += 1;
                i++;
                for (auto x = i; x < curr; x++) {
                    ck[x] = ck[x - 1];
                    ck[x]++;
                }
                notStop = true;
                /////
                for (int z = 0; z < m; z++) {
                    cout << ck[z] << " ";
                }
                cout << endl;
                break;
                /////
            }
        }
        if (!notStop) return 0;

    }
}