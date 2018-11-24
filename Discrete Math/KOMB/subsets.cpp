#include <iostream>
#include <vector>

using namespace std;
int n;

void search(vector<int> a, int last) {
    if (last == n) {
        return;
    }
    for (int i = last + 1; i <= n; i++) {
        a.push_back(i);
        for (int j = 0; j < a.size(); j++) {
            cout << a[j] << " ";
        }
        cout << endl;
        search(a, i);
        a.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("subsets.in", "r", stdin);
    freopen("subsets.out", "w", stdout);
    cin >> n;
    vector<int> a(0);
    cout<<endl;
    a.reserve(n);
    search(a, 0);
    return 0;
}