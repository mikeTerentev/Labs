#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

struct Window {
    int xl, yl, type, yr;

    Window(int x, int type, int y, int yy) {
        this->xl = x;
        this->type = type;
        this->yl = y;
        this->yr = yy;
    }

    bool operator<(const Window &wind) const {
        return ((wind.type < type && wind.xl == xl) || (wind.xl > xl));
    }
};

const int SHIFT_VAL = 2 * 100000;
int n, res, oxRes, oyRes;
vector<int> max_v, cur;
vector<Window> borders;

void propagate(int num, int l, int r) {
    int tmp = cur[num];
    cur[num] = 0;
    if (l != r) {
        max_v[2 * num + 1] += tmp, max_v[2 * num] += tmp;
        cur[2 * num + 1] += tmp, cur[2 * num] += tmp;
    }
}

void changeHere(int num, int l, int r, int yl, int yr, int type) {
    int middle = (l + r) >> 1;
    if (yl <= yr) {
        if (l != yl || yr != r) {
            propagate(num, l, r);
            changeHere(2 * num + 1, middle + 1, r, max(middle + 1, yl), yr, type);
            changeHere(2 * num, l, middle, yl, min(middle, yr), type);
            max_v[num] = max(max_v[2 * num + 1], max_v[2 * num]);
        } else {
            cur[num] += type, max_v[num] += type;
        }
    }
}

void updateMax(int num, int l, int r, int oxFixed) {
    int middle = (l + r) >> 1;
    if (l == r) {
        if (res < max_v[num]) {
            res = max_v[num];
            oyRes = l, oxRes = oxFixed;
        }
        return;
    }
    propagate(num, l, r);
    if (max_v[2 * num] <= max_v[2 * num + 1]) {
        updateMax(2 * num + 1, middle + 1, r, oxFixed);
    } else {
        updateMax(2 * num, l, middle, oxFixed);
    }
}


int main() {
    res = -1;
    int xl, xr, yl, yr;
    cur.assign(9 * SHIFT_VAL, 0), max_v.assign(9 * SHIFT_VAL, 0);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (size_t i = 1; i <= n; ++i) {
        cin >> xl >> yl >> xr >> yr;
        ++xl, ++xr, ++yl, ++yr;
        xl += SHIFT_VAL, xr += SHIFT_VAL, yl += SHIFT_VAL, yr += SHIFT_VAL;
        borders.emplace_back(xr, -1, yl, yr);
        borders.emplace_back(xl, 1, yl, yr);
    }
    sort(borders.begin(), borders.end());
    for (size_t i = 0; i < 2 * n; ++i) {
        changeHere(1, 1, 2 * SHIFT_VAL + 4, borders[i].yl, borders[i].yr, borders[i].type);
        updateMax(1, 1, 2 * SHIFT_VAL + 4, borders[i].xl);
    }
    cout << res << endl << oxRes - SHIFT_VAL - 1 << " " << oyRes - SHIFT_VAL - 1 << endl;

    return 0;
}