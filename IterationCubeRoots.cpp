#include <iostream>
using namespace std;

double IterationCube(double x, int N) {
    if (N == 0)
        return x;
    else
        return 2 * IterationCube(x, N - 1) / 3 + x / (3 * IterationCube(x, N - 1) * IterationCube(x, N - 1));
}

int main() {
    double x, N;
    while (cin >> x >> N)
        printf("%.6lf\n", IterationCube(x, N));
}
