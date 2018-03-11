#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    while (cin >> a) {
        sort(a.begin(), a.end());
        cout << a << endl;
    }
    return 0;
}
