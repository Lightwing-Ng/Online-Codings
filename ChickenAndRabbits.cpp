#include <iostream>
using namespace std;
void Fac(int a) {
    int sum = 1;
    for (int i = 1; i <= a; i++)
        sum *= i;
    cout << sum << endl;
}
void Calculate(int a, char c, int b) {
    if (c == '+')
        cout << a + b << endl;
    else if (c == '-')
        cout << a - b << endl;
    else if (c == '*')
        cout << a * b << endl;
    else if (c == '/')
        if (b == 0)
            cout << "error" << endl;
        else
            cout << a / b << endl;
    else if (c == '%')
        if (b == 0)
            cout << "error" << endl;
        else
            cout << a % b << endl;
}
int main() {
    int a, b;
    char c;
    while (cin >> a >> c)
        if (c == '!')
            Fac(a);
        else {
            cin >> b;
            Calculate(a, c, b);
        }
    return 0;
}
