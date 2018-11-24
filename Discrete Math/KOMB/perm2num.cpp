#include <iostream>
#include <vector>

using namespace std;

long long factorial(int x) {
    long long tmp = 1;
    for (int i = 1; i <= x; i++) {
        tmp *= i;
    }
    return tmp;
}

int main() {
    int m, z;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("perm2num.in", "r", stdin);
    freopen("perm2num.out", "w", stdout);
    int n;
    long long res = 0;
    cin >> n;
    vector<bool> used(n + 1);
    vector<int> cur_perm(0);
    vector<long long> perm(0);
    perm.reserve(n + 1);
    cur_perm.reserve(n + 1);
    cur_perm.push_back(0);
    used.push_back(false);
    perm.push_back(1);
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        cur_perm.push_back(tmp);
        used.push_back(false);
        perm.push_back(factorial(i));
    }


    for (auto i = 1; i < n + 1; i++) {
        m--;
        for (auto k = 1; k <cur_perm[i]; k++) {
            res = used[k] ? res : res + perm[n - i];
            m++;
        }
        //  cout << i << " " << m << ":" << m;
        used[cur_perm[i]] = used[cur_perm[i]] == false ? true : false;

    }
    cout << res;
    return 0;
}