#include <iostream>
#include<fstream>
#include<iostream>
#include<cstring>
#include <map>
#include <vector>


using namespace std;
int main(int args, char *arg[]) {
    FILE *file = fopen(arg[1], "r");
    char buf[100];
    size_t index = 0;
    string word = arg[2], key = "";
    while (!feof(file)) {
        size_t number = fread(buf, 1, 100, file);
        for (int i = 0; i < number; i++) {
            char symbol = buf[i];
            index++;
            if (isspace(symbol)) {
                key.clear();
            } else {
                key = key + symbol;
                if (key.size() == word.size()) {
                    if (word == key) {
                        cout << index - word.size() << " ";
                    }
                    key.erase(0, 1);
                }
            }
        }
    }
    return 0;
}
