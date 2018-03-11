#include <iostream>
using namespace std;

int FindGCD(int a, int b) {
    int res = a;
    while (res) {
        res = b % a;
        b = a;
        a = res;
    }
    return b;
}

int main(int argc, char const *argv[]) {
    int N, InitialPower;
    while (cin >> N >> InitialPower) {
        int B[N];
        for (int i = 0; i < N; cin >> B[i++]);
        for (int i = 0; i < N; ++i)
            if (B[i] <= InitialPower)
                InitialPower += B[i];
            else
                InitialPower += FindGCD(InitialPower, B[i]);
        cout << InitialPower << endl;
    }
}