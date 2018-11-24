#include <iostream>
#include<string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("allvectors.in", "r", stdin);
    freopen("allvectors.out", "w", stdout);
    int n;
    cin >> n;
    string x;
    for (int curr = 0; curr < (1 << n); curr++) {
        x="";
        for (int i = 0; i < n; i++) {
            curr & (1 << i) ? x = '1' + x : x = '0' + x;
        }
        cout << x << endl;
    }

    return 0;
}