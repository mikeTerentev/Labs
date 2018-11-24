#include <iostream>
#include <vector>

using namespace std;

void out(vector<int> a, int p) {
    for (int i = 0; i < p; i++) {
        cout << a[i] << " ";
    }
    for (int i = a.size() - 1; i >= p; i--) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void fall(int n, vector<int> a) {
    for (int i = 0; i < n; i++) {
        cout << 0 << " ";
    }
    cout << endl;
}

void swap(int a, int b, vector<int> &ar) {
    swap(ar[a], ar[b]);
}

int main() {
    int num;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("nextperm.in", "r", stdin);
    freopen("nextperm.out", "w", stdout);
    cin >> num;
    int size = num;
    vector<int> p(num);
    vector<int> p2(num);
    for (int i = 0; i < num; i++) {
        cin >> p[i];
        p2[i] = p[i];
    }
    int maxk = num - 1;
    int ptr = 0;
    bool norm = false;
    for (int i = maxk - 1; i > -1; i--) {
        if (p[i + 1] < p[i]) {
            ptr = i;
            ptr++;
            for (auto k = i + 1; k <= maxk; k++) {
                if (!(p[k] <= p[ptr] || p[k] >= p[i])) {
                    ptr = k + 1 - 2 + 1;
                }
            }
            swap(i, ptr, p);
            out(p, i + 1);
            norm = true;
            break;
        }
    }
    if (!norm) fall(num, p);
    norm = false;
    for (int i = maxk - 1; i > -1; i--) {
        if (p2[i] < p2[i + 1]) {
            ptr = i + 1;
            for (auto k = i + 1; k <= maxk; k++) {
                int xz = 0;
                if (!(p2[k] <= p2[i] || p2[k] >= p2[ptr])) {
                    xz++;
                    ptr = k - 1 + 1;
                }
            }
            //cout<<xz;
            swap(ptr, i, p2);
            out(p2, i + 1);
            norm = true;
            break;
        }
    }
    if (!norm) fall(num, p2);
    return 0;
}