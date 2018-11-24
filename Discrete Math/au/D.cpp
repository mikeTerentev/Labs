//
// Created by Михаил Терентьев on 27/05/2018.
//
#include <utility>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

char symbol;
int n, word_size;
vector<pair<string, string> > table;
long long dps[101][201][201];
string l_line, r_line, word;
pair<string, string> nd, cur_info;
string a, trash, b, nt, t;

int main() {
    freopen("nfc.in", "r", stdin);
    freopen("nfc.out", "w", stdout);
    cin >> n >> symbol;
    for (int i = 0; i < n; ++i) {
        a, trash, b;
        cin >> a >> trash >> b;
        table.emplace_back(a, b);
    }
    cin >> word;
    word_size =  word.size();
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < word_size; ++j) {
            for (int k = 0; k < word_size; ++k) {
                dps[i][j][k] = 0;
            }
        }
    }
    for (int ch = 0; ch < 26; ++ch) {
        for (int sze = 0; sze < word_size; ++sze) {
            for (int le = 0; le < n; ++le) {
                cur_info = table[le];
                nt = cur_info.first, t = cur_info.second;
                if (nt[0] == ch + 'A' && t[0] == word[sze]) dps[ch][sze][sze] = 1;
            }
        }
    }
    for (int j = word_size - 1; j >= 0; j--) {
        for (auto _sz = j + 1; _sz < word_size; _sz++) {
            for (auto chr = 0; chr < 26; chr++) {
                for (int ln = 0; ln < n; ln++) {
                    nd = table[ln];
                     l_line = nd.first, r_line = nd.second;
                    if (l_line[0] == chr + 'A' && r_line.size() == 2) {
                        for (auto z = j; z < _sz; z++) {
                            dps[chr][j][_sz] = (dps[chr][j][_sz] +
                                                (dps[r_line[0] - 'A'][j][z] * dps[r_line[1] - 'A'][z + 1][_sz]) %
                                                1000000007)
                                               % 1000000007;
                        }
                    }
                }
            }
        }
    }
    cout << dps[symbol - 'A'][0][word_size - 1] << endl;
    return 0;
}