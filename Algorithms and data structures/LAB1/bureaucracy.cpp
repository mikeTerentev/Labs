#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("bureaucracy.in", "r", stdin);
    freopen("bureaucracy.out", "w", stdout);
    int norma, n;
    long long sum = 0;
    cin >> n >> norma;
    vector<int> gopniki(0);
    queue<int> res;
    gopniki.reserve(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        gopniki.push_back(x);
        sum += x;
    }
      if (sum <= norma) {
          cout << -1 << endl;
          return 0;
      }
    /*  int l = 0, r = 1000000;
      while (r - l > 1) {
          int middle = l - (l - r) / 2;
          long long amount = 0;
          for (int person:gopniki) {
              amount += min(person, middle);
          }
          if (amount >= norma) {
              r = middle;
          } else {
              l = middle;
          }
      }
      long long amount = 0;
      for (int person:gopniki) {
          amount += (long long) min(person, l);
      }
      if (amount > (long long) norma) l--;*/
    int curr = 0;
    for (int i = 0; i < n; i++) {
        int l=norma/n;
        int x = gopniki[i] - l;
        if (x > 0) {
            res.push(gopniki[i] - l);
            curr += l;
        } else {
            curr += gopniki[i];
        }
    }
    norma -= curr;
    for (int i = 0; i < norma; i++) {
        int tmp = res.front() - 1;
        res.pop();
        if (tmp > 0) res.push(tmp);
    }
    cout << res.size() << endl;
    while (res.size() > 0) {
        cout << res.front() << " ";
        res.pop();
    }

    return 0;
}