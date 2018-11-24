#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, inp, tmp = "";
    string apl[1000];
    string x="nikita";
    x[0]='v';
    freopen("lzw.in", "r", stdin);
    freopen("lzw.out", "w", stdout);
    cin >> s;
    int n = s.size();
    for (int i = 0; i < 26; i++) {
        apl[i] = char('a' + i);
    }
    int nap = 26;
    tmp += s[0];
    for (int i = 1; i < n; i++) {
        bool flag = true;
        tmp += s[i];
        for (int j = 0; j < nap; j++) {
            if (tmp == apl[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            nap++;
            apl[nap-1] = tmp;
            tmp = apl[nap-1][apl[nap-1].size() - 1];
            string x=apl[nap-1].substr(0, apl[nap-1].size()-1);
            for (int j = 0; j < nap; j++) {
                if (x == apl[j]) {
                    cout << j << " ";
                    break;
                }
            }
        }
    }
    for (int j = 0; j < nap; j++) {
        if (tmp == apl[j]) {
            cout << j << " ";
            break;
        }
    }
    return 0;
}
