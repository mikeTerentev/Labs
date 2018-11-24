#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    cin >> num;
    int size = num;
    vector<int> dps(num);
    for (int i = 0; i < num; i++) {
        dps[i] = 1;
        cout << dps[i];
    }
    cout << endl;
    bool notStop = true;
    while (true) {
        int pre = size - 1;
        int delta = dps[pre];
        dps[pre] = 0;
        while (pre > 1 && dps[pre - 1] == dps[pre - 2]) {
            delta += dps[pre - 1];
            dps[pre - 1] = 0;
            pre--;
        }
        dps[pre - 1]++;

    }

    if (!notStop) return 0;

    cout <<
    return 0;
}