#include <iostream>
#include <vector>

using namespace std;

long long factorial(int x) {
    long long tmp = 1;
    for (long long i = 2; i <= x; i++) {
        tmp *= i;
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("num2perm.in", "r", stdin);
    freopen("num2perm.out", "w", stdout);
    int n, m, c = 0;
    long long num;
    cin >> n >> num;
    vector<bool> used(n + 1);
    vector<int> a(n + 1);
    for (auto i = 0; i <= n; i++) {
        used.push_back(false);
    }
    long long rankCost = 0;
    long long tmp = 0;
    for (auto i = 1; i < n + 1; i++) {
        rankCost = 0;
        tmp = factorial(n - i);
        long long soldOutNum = num / tmp;
        num %= tmp;
        c++;
        for (int curNum = 1; curNum < n + 1; curNum++) {
            m--;
            if (used[curNum] == false) {
                rankCost += 1;

                if (rankCost == soldOutNum + 1) {
                    a[i] = curNum;
                    if (used[curNum] == false) {
                        used[curNum] = true;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {

        cout << a[i] << " ";

    }
    return 0;
}