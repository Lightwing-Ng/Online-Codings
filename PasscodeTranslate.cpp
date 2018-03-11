#include <cstring>
#include <iostream>
#define MaxSize 100
using namespace std;

int main() {
    char s[MaxSize]; //定义待解密的字符串
    while (cin >> s && strcmp(s, "ENDOFINPUT")) { //结尾不为「ENDOFINPUT」继续输入
        cin.get();
        cin.getline(s, MaxSize);
        for (char *p = s; *p; p++) //指针开始只想s的首字母，
            if (isupper(*p)) //若为大写字母
                if (*p < 'F') //若A~E，ASCII码＋21转化成V~Z
                    *p += 21;
                else    //若F~Z，ASCII码-5转化成V~Z
                    *p -= 5;
        cout << s << endl;
        cin >> s;
    }
    return 0;
}
