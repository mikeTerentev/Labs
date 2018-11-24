#include <iostream>
#include <vector>

using namespace std;

void out(vector<int> a, int n, int last) {
    cout << n << "=";
    if (last > 0) {
        cout << a[0];
        for (auto i = 1; i < last; i++) {
            cout << a[i] << "+";
        }
    }
}

void plas() {
    cout << "+";
}

void fall() {
    cout << "No solution";
}

bool check(vector<int> a) {
    if (a.size() == 1) {
        return true;
    } else {
        return false;
    }
}


void nextPartition(vector<int> &part,vector<int> &final) {
 final.reserve(50);
    /////
    if (check(part)) {
        return;
    }
    int maxk = part.size() - 1;
    int prek = maxk - 1;
    part[maxk]--;
    part[prek]++;
    if (part[maxk] + 1 != 1 && part[prek] > part[maxk]) {
        for (int i = 0; i < part.size() - 2; i++) {
            cout << part[i] << "+";
            final.push_back(part[i]);
        }
        cout << part[maxk] + part[prek];
        final.push_back(part[maxk] + part[prek]);
        ///
        ///
    } else {
        for (int i = 0; i < part.size() - 2; i++) {
            cout << part[i];
            final.push_back(part[i]);
            plas();
        }
        cout << part[part.size() - 2];
        final.push_back(part[part.size() - 2]);
        if (part[maxk] != 0) {
            plas();
            while (part[maxk] + 1 > 2 * part[prek]) {
                cout << part[prek];
                final.push_back(part[prek]);
                plas();
                part[maxk] -= part[prek];
            }
            cout << part[maxk];
            final.push_back(part[maxk]);
        }
    }
    cout << endl;
    part.clear();
    nextPartition(final,part);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    vector<int> part(0);
    part.reserve(50);
    int n, tmp, m = 0;
    char tmp_char;
    cin >> n;
    part.reserve(n);
    vector<int> final(0);
    for(int i=0;i<n-1;i++){
        part.push_back(1);
        cout<<1<<"+";
    }
    part.push_back(1);
    cout<<1<<endl;
    nextPartition(part,final);
    return 0;
}

