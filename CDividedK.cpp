#include <cstdio>
#include <cstring>
#include <iostream>
#define maxn 31
using namespace std;

int bite[10]; // bite[2]-bite[9] 作为标志变量用于最后输出
int br[maxn]; // 存储输入的整数

void change(string str) { // 将字符串对应到 br 中
    memset(br, 0, sizeof(br));
    for (int i = 0; i < str.length(); ++i)
        br[++br[0]] = str[i] - '0';
}

void solve() { // 计算 2 - 9
    memset(bite, 0, sizeof(bite));
    int y = 0, i = 1;
    for (int j = 2; j <= 9; ++j) {
        y = 0;
        i = 1;
        while (i <= br[0]) {
            y = y * 10 + br[i++];
            y %= j;
        }
        bite[j] += y;
    }
}

void output() { // 输出
    int flag = 0;
    for (int j = 2; j <= 9; ++j)
        if (bite[j] == 0) {
            if (flag == 1)
                cout << " ";
            flag = 1;
            cout << j;
        }
    if (flag == 0)
        cout << "none";
}

int main() {
    string str;
    while (cin >> str) {
        if (str == "-1")
            break;
        change(str);
        solve();
        output();
        cout << endl;
    }
    return 0;
}
