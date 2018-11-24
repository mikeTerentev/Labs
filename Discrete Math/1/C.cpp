#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool isT0(string &f, int var) {
    bool T0 = false;
    if (f[0] == '0') {
        T0 = true;
    }
    return T0;
}

bool isT1(string &f, int var) {
    bool T1 = false;
    int n = (int) pow(2, var);
    if (f[n - 1] == '1') {
        T1 = true;
    }
    return T1;
}

bool isM(string &f, int var) {
    int n = 1 << var;
    bool M = true;
    for (int i = 0; i < n ; i++) {
        for (int k = i; k < n; k++) {
            if ((i & k) == i && f[i] > f[k]) {
                M = false;
            }
        }
    }
    return M;
}

/* int n = (int) pow(2, var);
 bool M = true;
 for (int i = 0; i < n; i++) {
     for (int k = 0; k < var; k++) {
         int bit = 0;
         i & (1 << k) ? bit = 1 : bit = 0;
         if (bit == 1) {
             int mask = i ^(1 << k);
             if (f[mask] > f[k]) {
                 M = false;
             }
         }
     }
 }*/


bool isD(string &f, int var) {
    bool D = true;
    int l = 0;
    int r = (int) pow(2, var) - 1;
    if (f.size() == 1) {
        D = false;
    }
    while (l < r) {
        if (f[l] == f[r]) {
            D = false;       //~~~
        }
        l++;
        r--;
    }
    return D;
}

bool isL(string &f, int var) {
    bool L = true;
    int n = 1 << var;
    vector<int> a(n);
    vector<int> kof(n);
    vector<int> as(n);//хранит  количство 1
    // узнаем сколько единиц в табл ист
    for (int i = 0; i < n; i++) {
        int z = i;
        as[i] = 0;
        while (z > 0) {
            as[i] += z % 2;
            z /= 2;
        }
    }
    for (int k = 0; k < n; k++)
        a[k] = f[k] - '0';
    kof[0] = a[0];
    int j = 1;
    int k = n - 1;
    while (k > 0) {
        for (int i = 0; i < k; i++) {
            a[i] = (a[i] + a[i + 1]) % 2;
        }
        kof[j] = a[0];
        j++;
        k--;
    }
    for (int i = 0; i < n; i++) {
        if (kof[i] == 1 && as[i] > 1) {
            L = false;
        }
    }

    return L;
}

int main() {
    int n, var;
    string f;
    cin >> n;
    bool T0 = true;
    bool T1 = true;
    bool D = true;
    bool M = true;         //~~~
    bool L = true;
    for (int i = 0; i < n; i++) {
        cin >> var >> f;


        if (var == 0) {
            D = false;
            if (f[0] == '0') {
                T1 = false;
            } else {
                T0 = false;
            }
        } else {
            if (!isT0(f, var)) T0 = false;
            if (!isT1(f, var)) T1 = false;
            if (!isM(f, var)) M = false;
            if (!isD(f, var))D = false;
            if (!isL(f, var))L = false;
        }
    }
    if (!M && !D && !T0 && !T1 && !L) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}