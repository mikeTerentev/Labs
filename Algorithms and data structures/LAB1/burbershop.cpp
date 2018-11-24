#include <iostream>
#include <list>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("saloon.in", "r", stdin);
    freopen("saloon.out", "w", stdout);
    int person, min, hours, amount, start, clients, time, free;
    cin >> person;
    start = 0;
    free = 0;
    clients = 0;
    for (int i = 1; i <= person; i++) {
        cin >> hours >> min >> amount;
        time = 60 * hours + min;
        if (time < free) {
            int x = (time - start) / 20;
            clients -= x;
            start += x * 20;
            if (amount < clients) {
                cout << time / 60 << " " << time % 60 << endl;
            } else {
                cout << (free + 20) / 60 << " " << (free + 20) % 60 << endl;
                free = free + 20;
                clients++;
            }
            continue;
        }
        cout << (time + 20) / 60 << " " << (time + 20) % 60 << endl;
        clients = 1;
        start = time;
        free = time + 20;
    }
    return 0;
}