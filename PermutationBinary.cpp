#include <iostream>
using namespace std;

int BinaryCount(int N) {
    int count = 0;
    while (N % 2 == 0) {
        N >>= 1;
        count++;
    }
    return count;
}

int main() {
    int M, N, count;
    while (cin >> N >> M && N) {
        count = 0;
        for (int i = 0; i < M; i++)
            count += BinaryCount(N - i);
        cout << count << endl;
    }
}

/*
#include <iostream>
using namespace std;

int Fac(int N) {
    if (N == 0 || N == 1)
        return 1;
    else
        return N * Fac(N - 1);
}

int PermutationBinary(int N, int M) {
    int result = Fac(N) / Fac(N - M), count = 0;
    while (result) {
        if (result % 2 == 0) {
            count++;
            result /= 2;
        } else
            break;
    }
    return count;
}

int main() {
    int N, M;
    while (cin >> N >> M && N)
        cout << PermutationBinary(N, M) << endl;
}
 */
