#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> used;
vector<int> x;
vector<int> y;

int n, m, cur_comp = 1;

double f(int i, int j) {
    return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

double res = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const double INF = 100000;
    int n;
    std::cin >> n;
    x.resize(n);
    y.resize(n);
    used.resize(n);
    std::vector<double> min_dist(n, INF);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    for (int i = 1; i < n; i++) {
        min_dist[i] = f(i, 0);
    }
    min_dist[0] = 0;
    used[0] = true;
    while (true) {
        double min_edge = INF;
        int next = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                if (min_edge > min_dist[i]) {
                    next = i;
                    min_edge = min_dist[i];
                }
            }
        }
        if (next != 0) {
            min_dist[next] = 0;
            used[next] = true;
            for (int i = 1; i < n; i++) {
                if (!used[i]) {
                    if (f(next, i) < min_dist[i]) {
                        min_dist[i] = f(next, i);
                    }
                }
            }
            res += min_edge;
        } else {
            break;
        }
    }
    std::cout << res;
}