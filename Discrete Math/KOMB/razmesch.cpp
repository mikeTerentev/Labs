#include <iostream>
using namespace std;
void swap(int *a, int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}
bool NextSet(int *a, int n, int m)
{
    int j;
    do  // повторяем пока не будет найдено следующее размещение
    {
        j = n - 1;
        while (j != -1 && a[j] >= a[j + 1]) j--;
        if (j == -1)
            return false; // больше размещений нет
        int k = n - 1;
        while (a[j] >= a[k]) k--;
        swap(a, j, k);
        int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
        while (l < r)
            swap(a, l++, r--);
    } while (j > m - 1);
    return true;
}
void Print(int *a, int n)  // вывод размещения
{
    static int num = 1; // номер размещения
    cout.width(3); // ширина поля вывода номера размещения
    cout << num++ << ":  ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int n, m, *a;
    cout << "N = ";
    cin >> n;
    cout << "M = ";
    cin >> m;
    a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    Print(a, m);
    while (NextSet(a, n, m))
        Print(a, m);
    cin.get(); cin.get();
    return 0;
}