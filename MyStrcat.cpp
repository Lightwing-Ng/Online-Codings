#include <iostream>
#include <string>
using namespace std;

void MyStrcat(char str_1[], char str_2[], char str[]) {
    char *p = str_1, *q = str_2, *r = str;
    while (*p != '\0')
        *r++ = *p++;
    while (*q != '\0')
        *r++ = *q++;
    *r = '\0';
}

int main(void) {
    char str_1[100 + 1], str_2[100 + 1], str[200 + 1];
    while (cin >> str_1 >> str_2) {
        MyStrcat(str_1, str_2, str);
        cout << str << endl;
    }
    return 0;
}
