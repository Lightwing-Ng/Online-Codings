#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string str;
    while (cin >> str) {
        for (int i = 0; i < str.length(); i++)
            cout << str[str.length() - 1 - i];
        cout << endl;
    }
    return 0;
}
