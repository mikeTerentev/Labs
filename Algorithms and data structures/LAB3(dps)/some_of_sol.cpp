#include <iostream>

#include <vector>
#include <string>
#include <set>
#include <stack>

#define  f first
#define  s second
#define  inp pair<long,long>

using namespace std;

/*
void kuznechik(vector<int> cost, int n, int k) {
    long long dps[cost.size()], highestCash = 0;
    int pre[n], len[n];
    dps[0] = 0;
    for (int i = 1; i < n; i++) {
        dps[i] = -1;
        pre[i] = 0;
        len[i] = -1;
        int ptr = i - 1, max = 0;
        while (ptr > -1) {
            if (dps[ptr] > max && ptr + k >= i) {
                pre[i] = ptr;
                len[i] = len[ptr] + 1;
                max = dps[ptr];
            }
            ptr--;
        }
        dps[i] = max + cost[i];
    }
    cout << dps[n - 1] << endl;

    set<int> final;
    final.insert(n);
    int ptr = n - 1;
    int l = 0;
    while (ptr > 0) {
        l++;
        int now = pre[ptr] + 1;
        final.insert(now);
        ptr = pre[ptr];
    }
    final.insert(1);
    cout << l << endl;
    for (auto i : final) {
        cout << i << " ";
    }
}

int Levenshtein_distance(string a, string b) {
    long long add, trash, mach;
    long long first = a.size();
    long long second = b.size();
    int dps[first + 1][second + 1];
    for (auto i = 0; i < first + 1; i++) {
        for (auto k = 0; k < second + 1; k++) {
            if (!(k != 0) || !(i != 0)) {
                dps[i][k] = i + k;
            } else {
                dps[i][k] = min({dps[i][k - 1] + 1,
                                 dps[i - 1][k] + 1,
                                 dps[i - 1][k - 1] + (a[first - i] != b[second - k])});
            }
        }
    }
    return dps[first][second];
}

void maxSubset(vector<int> set, int n) {
    long long dps[set.size()], res = 0;
    int pre[n];
    for (int i = 0; i < n; i++) {
        dps[i] = 1;
        pre[i] = -2;
        int k = i - 1, max = 0;
        while (k > -1) {
            if (dps[k] > max && set[k] < set[i]) {
                pre[i] = k;
                max = dps[k];
            }
            k--;
        }
        dps[i] = 1 + max;
        res = res < dps[i] ? dps[i] : res;
    }
    cout << res << endl;
    //fix
    int cur = 0;
    for (int i = 1; i < n; i++) {
        if (dps[cur] < dps[i]) cur = i;
    }
    long long final[res];
    int ptr = res - 1;
    while (cur >= 0) {
        final[ptr] = set[cur];
        ptr--;
        cur = pre[cur];
    }
    for (int i = 0; i < res; i++) {
        cout << final[i] << " ";
    }
}

long long oneNumber(int size) {
    long long d[size + 1][10];
    d[size][5] = 0;
    for (int n = 1; n <= size; n++) {
        for (int last = 0; last <= 9; last++) {
            if (n == 1) {
                if (last == 8 || last == 0) {
                    d[n][last] = 0;
                } else {
                    d[n][last] = 1;
                }
                continue;
            }
            switch (last) {
                case 0: {
                    d[n][0] = (d[n - 1][4] + d[n - 1][6]) % 1000000000;
                    continue;
                }
                case 9: {
                    d[n][9] = (d[n - 1][2] + d[n - 1][4]) % 1000000000;
                    continue;
                }
                case 8: {
                    d[n][8] = (d[n - 1][1] + d[n - 1][3]) % 1000000000;
                    continue;
                }
                case 7: {
                    d[n][7] = (d[n - 1][2] + d[n - 1][6]) % 1000000000;
                    continue;
                }
                case 6: {
                    d[n][6] = (d[n - 1][0] + (d[n - 1][1] + d[n - 1][7])) % 1000000000;
                    continue;
                }
                case 4: {
                    d[n][4] = (d[n - 1][0] + (d[n - 1][9] + d[n - 1][3])) % 1000000000;
                    continue;
                }
                case 3: {
                    d[n][3] = (d[n - 1][8] + d[n - 1][4]) % 1000000000;
                    continue;
                }
                case 2: {
                    d[n][2] = (d[n - 1][9] + d[n - 1][7]) % 1000000000;
                    continue;
                }
                case 1: {
                    d[n][1] = (d[n - 1][8] + d[n - 1][6]) % 1000000000;
                    continue;
                }

            }
        }
    }
    long long res = 0;
    for (int i = 0; i <= 9; i++) {
        res = (res + d[size][i]) % 1000000000;
    }
    return res;
}

void out(vector<vector<int>> a, int k) {
    for (auto i = 0; i < a.size(); i++) {
        for (auto j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";

        }
        cout << endl;
    }
    cout << endl;
}

void in(vector<int> &a, int n, int &k) {
    for (auto i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 100) k++;
    }
}

void cafe(int n, vector<int> c, int k) {
    vector<vector<int>> a(n + 2);
    int pre[n + 2][n + 2];
    //
    a[0].push_back(0);
    for (auto i = 1; i <= n + 1; i++) a[0].push_back(1000000);
    //
    a[1].push_back(c[1]);

    if (c[1] > 100) {
        a[1].push_back(c[1]);
    } else {
        a[1].push_back(10000000);
    }

    for (auto i = 1; i <= n; i++) {
        for (auto j = 0; j <= n; j++) {
            if (i == 1 && j > 1) a[i].push_back(10000000);
            if (i != 1) {
                if (c[i] <= 100) {
                    a[i].push_back(min(a[i - 1][j] + c[i], a[i - 1][j + 1]));
                    pre[i][j] = a[i - 1][j + 1] < a[i - 1][j] + c[i] ? 2 : 1;
                } else {
                    if (j == 0) {
                        a[i].push_back(min(10000000, a[i - 1][j + 1]));
                        pre[i][j] = a[i - 1][j + 1] < 10000000 ? 2 : 3;
                    } else {
                        a[i].push_back(min(a[i - 1][j - 1] + c[i], a[i - 1][j + 1]));
                        pre[i][j] = a[i - 1][j + 1] < a[i - 1][j - 1] + c[i] ? 2 : 3;
                    }
                }
            }
            // cout << i << " " << j << " : " << a[i][j] << "| ";
        }
        // 1 петя покупает
        // 2 по купону
        // 3 получает купон
        a[i].push_back(10000000);
        //cout << endl;
    }
    int j = 0, minj;

    if (a[n][1] <= a[n][0]) j = 1;

    cout << a[n][j] << endl;
    minj = j;
    vector<int> res(0);
    for (int i = n; i > 0; i--) {
        if (pre[i][j] == 1) {
            //new  val = a[i - 1][j] + c[i];
            continue;
        }
        if (pre[i][j] == 2) {
            res.push_back(i);
            //new  val = a[i - 1][j + 1];
            j++;
            continue;
        }
        if (pre[i][j] == 3) {
            //new a[i - 1][j - 1] + c[i];
            j--;
            continue;
        }
    }
    cout << minj << " " << res.size() << endl;
    for (int i = res.size() - 1; i > -1; i--) {
        cout << res[i] << endl;
    }

}

bool isPossible(int map1, int map2, int n) {
    for (int cur = 0; cur < n - 1; cur++) {
        pair<int, int> p1, p2;
        p1.f = map1 & (1 << cur) ? 1 : 0;
        p2.f = map2 & (1 << cur) ? 1 : 0;
        p1.s = map1 & (1 << (cur + 1)) ? 1 : 0;
        p2.s = map2 & (1 << (cur + 1)) ? 1 : 0;
        if (p1.f == 1 && p1.s == 1 && p2.f == 1 && p2.s == 1) {
            return false;
        }
        if (p1.f == 0 && p1.s == 0 && p2.f == 0 && p2.s == 0) {
            return false;
        }
    }
    return true;
}

void niceObjects(int n, int m) {
    int isOk[1 << n][1 << n];
    int dps[m + 1][2 << n + 1];
    for (int st = 1; st < m; st++) {
        for (int p1 = 0; p1 < (1 << n); p1++) {
            dps[st][p1] = 0;
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        dps[0][i] = 1;
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            isOk[i][j] = isPossible(i, j, n) ? 1 : 0;
        }
    }
    for (int st = 1; st < m; st++) {
        for (int p1 = 0; p1 < (1 << n); p1++) {
            for (int p2 = 0; p2 < (1 << n); p2++) {
                dps[st][p1] += dps[st - 1][p2] * isOk[p2][p1];
                //  cout<<dps[st][p1]<<" ";
            }
            //    cout<<endl;
        }
    }
    long long res = 0;
    m--;
    for (int str = 0; str < (1 << n); str++) {
        res += dps[m][str];
    }
    cout << res;
}*/

void out(vector<char> &a, int f, int le) {
    for (auto i = f; i < f + le; i++) {
        cout << a[i];
    }
}

void readAns(int l, int r, vector<vector<int>> pre, vector<char> &s, vector<vector<int>> &d) {
    int balance = r - l;
    //exit
    if (pre[l][r] == -3) {
        cout << s[l - 1];
        readAns(l + 1, r - 1, pre, s, d);
        cout << s[r - 1];
        return;
    }
    if (d[l][r] == balance + 1)
        return;
    if (d[l][r] == 0) {
        out(s, l - 1, balance + 1);
        return;
    }
    //parts
    readAns(l, pre[l][r], pre, s, d);
    readAns(pre[l][r] + 1, r, pre, s, d);
}

void del_Skobli(vector<char> &s) {
    int r, ok2u, size = s.size();
    vector<vector<int>> d(0);
    vector<vector<int>> pre(0);

    for (int i = 0; i <= size; ++i) {
        vector<int> right(size + 1, 0);
        d.push_back(right);
        pre.push_back(right);
        d[i][i] = 1;
    }
    int take;
    for (auto len = 2; len <= size; len++) {
        int tmp = len - 1;
        for (auto l = 1; l <= size - tmp; l++) {
            r = l + tmp;
            ok2u = INT_MAX;
            take = -3;
            if ((s[l - 1] == '[' && s[r - 1] == ']') ||
                (s[l - 1] == '(' && s[r - 1] == ')' || (s[l - 1] == '{' && s[r - 1] == '}')))
                ok2u = min(ok2u, d[l + 1][r - 1]);

            for (int ptr = l; ptr <= r - 1; ptr++) {
                if (d[ptr + 1][r] + d[l][ptr] < ok2u) {
                    ok2u = min(d[l][ptr] + d[ptr + 1][r], ok2u);
                    take = ptr;
                }
            }
            pre[l][r] = take;
            // cout << take << " ";
            d[l][r] = ok2u;

        }
    }
    //cout << size-d[1][size] << endl;
    readAns(1, size, pre, s, d);
}


bool isIncrease(int vertex, vector<vector<int>> &table, int *res, bool *visited) {
    if (!visited[vertex]) {
        int neww;
        visited[vertex] = true;
        int i = 0;
        while (i <= table[vertex].size() - 1) {
            neww = table[vertex][i];
            int s = 1;
            if ((res[neww] > -2 && res[neww] < 0) || isIncrease(neww, table, res, visited)) {
                //cout<<res[neww]<<endl;
                res[neww] = vertex;
                return true;
            }
            i++;
        }
        return false;
    } else {
        return false;
    }
}

void kommivoyager(int n) {
    vector<long long> ans;
    long long res = LONG_LONG_MAX, cur, curMap = (1 << n) - 1;
    vector<vector<long long>> matrix(static_cast<unsigned int>(n + 1),
                                     vector<long long>(static_cast<unsigned int>(n + 1), 0));
    vector<vector<long long>> dp((1 << n), vector<long long>(n, LONG_LONG_MAX));
    vector<vector<long long>> prev((1 << n), vector<long long>(n, -3));
    for (auto i = 0; i <= n - 1; i++) dp[1 << i][i] = 0;
    for (auto i = 0; i <= n - 1; i++) for (auto j = 0; j < n; ++j) cin >> matrix[i][j];
    for (auto mask = 0; mask < 1 << n; mask++) {
        for (auto curr = 0; curr <= n - 1; curr++) {
            if (1 == ((mask >> curr) & 1)) {
                for (auto next = 0; next <= n - 1; next++) {
                    if (dp[mask ^ (1 << next)][next] > matrix[curr][next] + dp[mask][curr]) {
                        dp[mask | (1 << next)][next] = matrix[curr][next] + dp[mask][curr];
                        prev[mask][next] = curr;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (res > dp[(1 << n) - 1][i]) {
            res = dp[(1 << n) - 1][i];
            cur = i;
        }
    }
    cout << res << endl;
    while (cur != -3) {
        curMap = curMap - (1 << cur);
        ans.push_back(cur);
        cur = prev[curMap][cur];
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] + 1 << " ";
}

int n;


void findSet(int x, vector<vector<int>> &matrix, vector<int> &c, vector<int> &notC) {
    if (matrix[x].size() == 0) {
        c[x] = 1;
        notC[x] = 0;
        return;
    }
    for (auto i = 0; i < matrix[x].size(); i++)
        findSet(matrix[x][i], matrix, c, notC);

    for (auto i = 0; i < matrix[x].size(); i++) {
        c[x] += notC[matrix[x][i]];
        notC[x] += max(notC[matrix[x][i]], c[matrix[x][i]]);
    }
    c[x] += 1;
}

void bin(vector<long > &x) {
    x.clear();
}

void compare(long bitMap, vector<inp > &dp) {
    dp[bitMap].f = dp[bitMap].s = 100;
}

int main() {
    freopen("skyscraper.in", "r", stdin);
    freopen("skyscraper.out", "w", stdout);
    vector<long> elevator(0);
    vector<inp > dp((1ll << 18) + 2);
    inp sec;
    long n, maxWeight, pr[(1ll << 18) + 2], currMass, mask, bit, bitcard;
    elevator.reserve(n);
    cin >> n >> maxWeight;
    vector<long> cowsWeight(0);
    cowsWeight.reserve(n);
    for (auto k = 0; k < n; k++) {
        long tmp;
        cin >> tmp;
        cowsWeight.push_back(tmp);
    }
    dp[0].f = 1;
    dp[0].s = 0;
    long alls = (1u << n);
    for (auto bitMap = 1; bitMap <= alls - 1; ++bitMap) {
        compare(bitMap, dp);
        for (auto i = 0; i <= n - 1; ++i) {
            bit = bitMap & (1u << i);
            if (!(bit)) continue;
            bitcard = bitMap ^ (1u << i);
            sec = dp[bitcard];
            sec.f = sec.s > maxWeight - cowsWeight[i] ? sec.f + 1 : sec.f;
            sec.s = sec.s > maxWeight - cowsWeight[i] ? cowsWeight[i] : sec.s + cowsWeight[i];
            if (dp[bitMap] > sec) {
                pr[bitMap] = i;
                dp[bitMap] = sec;
            }
        }
    }
    cout << dp[(1 << n) - 1].f << endl;
    mask = alls - 1;
    currMass = dp[alls - 1].s;
    while (mask > 0) {
        long tmp = pr[mask] + 1;
        elevator.push_back(tmp);
        currMass = currMass - cowsWeight[pr[mask]];
        mask = mask ^ (1 << pr[mask]);

        if (!currMass) {
            cout << elevator.size();
            for (auto i = 0; i <= elevator.size() - 1; ++i) cout << " " << elevator[i];
            cout << endl;
            bin(elevator);
            currMass = dp[mask].s;
        }
    }
    return 0;
}