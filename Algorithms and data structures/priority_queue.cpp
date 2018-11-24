#include <fstream>
#include <iostream>

using namespace std;
int rankAr[110000];
pair<int, int> heap[110000];
int size;

void siftUp(int i) {
    if (i == 1 || i == 0) return;
    if (heap[i / 2].second > heap[i].second) {
        rankAr[heap[i].first] = i / 2;
        rankAr[heap[i / 2].first] = i;
        swap(heap[i / 2], heap[i]);
        siftUp(i / 2);
    }
    return;
}

void siftDown(int i) {
    int Ieft = i * 2;
    if (Ieft > size) return;
    int right = (i * 2 + 1);
    if (right > size) {
        if (heap[Ieft].second < heap[i].second) {
            rankAr[heap[i].first] = Ieft;
            rankAr[heap[Ieft].first] = i;
            swap(heap[Ieft], heap[i]);
            i = Ieft;
            siftDown(i);
        }
    } else {
        if (heap[Ieft].second < heap[right].second) {
            if (heap[i].second > heap[Ieft].second) {
                rankAr[heap[i].first] = Ieft;
                rankAr[heap[Ieft].first] = i;
                swap(heap[Ieft], heap[i]);
                siftDown(Ieft);
            }
        } else {
            if (heap[i].second > heap[right].second) {
                rankAr[heap[i].first] = right;
                rankAr[heap[right].first] = i;
                swap(heap[right], heap[i]);
                siftDown(right);
            }
        }
    }
}

int main() {
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    int dump = 0;
    while (true) {
        string kek;
        cin >> kek;
        if (kek == "") break;
        dump++;
        if (kek == "push") {
            size++;
            int q;
            cin >> q;
            heap[size].second = q;
            heap[size].first = dump;
            rankAr[dump] = size;
            siftUp(size);
        } else if (kek == "extract-min") {
            if (size != 0) {
                cout << heap[1].second << '\n';
                swap(heap[1], heap[size]);
                size--;
                siftUp(1);
                siftDown(1);
            } else {
                cout << "*" << '\n';
            }
        } else if (kek == "decrease-key") {
            int rank, neew;
            cin >> rank >> neew;
            heap[rankAr[rank]].second = neew;
            siftUp(rankAr[rank]);
            siftDown(rankAr[rank]);
        }

    }
    return 0;
}







