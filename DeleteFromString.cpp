#include <iostream>
using namespace std;

int main() {
    string s, c;
    while (cin >> s >> c) {
        int flag[100] = { 0 }; //标记数组，初始化为0，若为删除字符标记为1
        for (int i = 0; i < s.length(); i++)
            if (s[i] == c[0])
                flag[i] = 1;
        for (int i = 0; i < s.length(); i++)
            if (flag[i] == 1)
                continue;
            else
                cout << s[i];
        cout << endl;
    }
    return 0;
}
