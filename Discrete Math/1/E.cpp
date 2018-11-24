
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int trl[40][40], res[40], deep[40];
    vector<int> unput[40], tops, les;
    for (int i = 0; i < 28; i++) {
        deep[i] = 0;
        res[i] = 0;
    }
    int n, frnd;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int cur;
        cin >> cur;
        if (cur != 0) {
            tops.push_back(i);
            for (int j = 0; j < cur; ++j) {
                cin >> frnd;
                deep[i] = max(deep[i], deep[frnd] + 1);
                unput[i].push_back(frnd);
            }
            for (int j = 0; j < (1 << cur); ++j) {
                cin >> trl[i][j];
            }
        } else {
            deep[i] = 0;
            les.push_back(i);
        }
    }
    cout << deep[n];
    cout << endl;
    int ptr = les.size();
    for (int i = 0; i < (1 << ptr); ++i) {
        for (int j = 0; j < ptr; ++j) {
            i & (1 << ptr - j - 1) ? res[les[j]] = 1 : res[les[j]] = 0;
        }

        for (int i = 0; i < tops.size(); i++) {
            int value = 0;
            for (int j = 0; j < unput[tops[i]].size(); ++j) {
                value = 2 * value + res[unput[tops[i]][j]];
            }
            res[tops[i]] = trl[tops[i]][value];
        }
        cout << res[n];
    }
}


