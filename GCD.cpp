#include <iostream>
using namespace std;

int main() {
    int M, N;
    while (cin >> M >> N) {
        int res = 1;
        while (res) {
            res = M % N;
            M = N;
            N = res;
        }
        cout << M << endl;
    }
    return 0;
}
