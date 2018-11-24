#include <iostream>

using namespace std;

void change(int &x) {
    if (x != 1) {
        x = (x - 1) % 2;
    }
}

int main() {

    int res_part[512];
    int func[512][512];
    int res_var[512];
    int n, ndiz, tmp;
    bool isEmpty[512];
    cin >> n >> ndiz;
    for (int i = 0; i < 512; i++) {
        res_var[i] = 0;
        res_part[i] = -3;
        isEmpty[i] = 0;
    }
    ///////////////////////////////
    for (int i = 0; i < ndiz; i++) {
        //cout<<"(";
        for (int j = 0; j < n; j++) {
            cin >> func[i][j];
            //cout<<func[i][j]<<" | ";
        }
        //cout<<")";
    }  //cout<<endl;
    /////////////////////////////////
    bool again = true;
    bool finish = true;
    while (again) {
        again = false;
        for (int i = 0; i < ndiz; i++) {  //берем (...)
            if (isEmpty[i] == 0) {
                int ths_ok = 0;
                int val_ok = 0;
                int n_ok = 0;
                for (int j = 0; j < n; j++) {
                    tmp = func[i][j];
                    change(tmp);
                    if (res_var[j] * tmp == 1) {
                        val_ok = func[i][j];
                        isEmpty[i] = 1;
                        //cout<<"isEmpty"<<"["<<i<<"]";
                        if (isEmpty[i] == 1) break;
                    }
                    int z = !res_var[j];
                    if (z && tmp) {
                        n_ok++;
                        ths_ok = j;
                    }
                }
                if (n_ok == 1 && isEmpty[i] == 0) {
                    again = true;
                    res_part[i] = 1;
                    tmp = func[i][ths_ok];
                    change(tmp);
                    //cout<<"ths_ok="<<ths_ok<<" ";
                    res_var[ths_ok] = tmp;

                }
            }
        }
    }
    /* cout << endl;
     for (int x:res_part) {
         cout << x << " ";
     }
     cout << endl;*/
    //проверка
    for (int i = 0; i < ndiz; ++i) {
        bool curr = false;
        if (isEmpty[i] == 0) {
            for (int j = 0; j < n; ++j) {
                if (res_var[j] == 0) {
                    res_var[j] = -1;
                }
                tmp = func[i][j];
                change(tmp);
                int tmp2 = res_var[j] * tmp;
                curr = (curr | (tmp2 == 1));
            }
            finish &= curr;
            //cout<<finish<<" ";
        }
    }
    if (finish) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}