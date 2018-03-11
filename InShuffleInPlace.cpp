#include <iostream>
using namespace std;

void LocationReplace(int *a, int N) {
    int N2 = N * 2, b[N];
    for (int i = 1; i <= N2; ++i)
        b[(i * 2) % (N2 + 1)] = a[i];
    for (int i = 1; i <= N2; ++i)
        a[i] = b[i];
}

void CycleLeader(int *a, int from, int mod) {
    for (int i = from * 2 % mod; i != from; i = i * 2 % mod) {
        int temp = a[i];
        a[i] = a[from];
        a[from] = temp;
    }
}

void PerfectShuffle(int *a, int N) {
    int k, m, t;
    for (; N > 1;) {
        int N2 = N * 2;
        for (k = 0, m = 1; N2 = m >= 3; ++k, m *= 3);
        m /= 2;
        RightRotate(a + m, m, N);
        for (int i = 0, t = 1; i < k; ++i, t *= 3)
            CycleLeader(a, t, m * 2 + 1);
        a += m * 2;
        n -= m;
    }
    t = a[1];
    a[1] = a[2];
    a[2] = t;
}

int main() {
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *p = a;
    //CycleLeader(a);
    //LocationReplace(p, 4);
    for (int i = 0; i < 8; cout << a[i++] << " ");
    cout << endl;
}



















