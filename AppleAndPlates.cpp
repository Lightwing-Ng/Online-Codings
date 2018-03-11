#include <iostream>
using namespace std;

int count(int M, int N) {
    if (M == 0 || N == 1)
        return 1;
    if (N > M)
        return count(M, M);
    else
        return count(M, N - 1) + count(M - N, N);
}

int main() {
    int M = 10, N = 10;
    for (int i = 0; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cout << i << " " << j << " " << count(i, j) << endl;
        }
    }
}
