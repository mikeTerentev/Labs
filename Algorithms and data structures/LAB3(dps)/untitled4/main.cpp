#include <iostream>
#include <map>
#include <vector>

using namespace std;

int random(int n) {
    return rand() % n;
}

int main()
{
    int n, k;
    cin >> n >> k;
    map <int, int> arr;

    vector <int> generated(0);
    for (int i = 0; i < k; ++i) {
        int index = random(n - i);
        auto get = [&arr](int key) {
            if (arr.count(key))
                return arr[key];
            return key;
        };

        //Удаляем из вектора элемент с index.
        int a = get(index);
        int b = get(n - i - 1);
        arr[index] = b;

        generated.push_back(a + 1);
    }
    for (auto x : generated) {
        cout << x << " ";
    }
    return 0;
}