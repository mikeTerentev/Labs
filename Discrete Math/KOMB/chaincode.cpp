#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("chaincode.in", "r", stdin);
    freopen("chaincode.out", "w", stdout);
    int n;
    set<string> table;
    string thisV = "";
    cin >> n;
    for (int i = 0; i < n; i++) {
        thisV = thisV + '0';
    }
    table.insert(thisV);
    cout<<thisV<<endl;
    for (size_t i = 1; i < pow(2, n); i++) {
        string prfx="";
        for(int j=1;j<n;j++){
            prfx+=thisV[j];
        }
        if (table.count(prfx + '1') == 0) {
            thisV = prfx + '1';
        } else {
            if (table.count(prfx + '0') == 0) {
                thisV = prfx + '0';
            }
        }
        table.insert(thisV);
        cout<<thisV<<endl;
    }
    return 0;
}