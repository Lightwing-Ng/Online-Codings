#include <iostream>
#include <string>
using namespace std;

int main() {
    string S1, S2;
    while (cin >> S1 >> S2) {
        int lenS1 = S1.length(), lenS = 2 * lenS1;
        for (int i = 0; i < lenS; i++)
            if (i % 2 == 0)
                cout << S1[i / 2];
            else
                cout << S2[(lenS - i) / 2];
        cout << endl;
    }
}
