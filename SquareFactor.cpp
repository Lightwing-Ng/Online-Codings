#include <iostream>
using namespace std;

int SquareFactor(int N) {
    for (int i = 2; i * i <= N; i++)
        if (N % (i * i) == 0)
            return 1;
    return 0;
}

int main() {
    int N;
    while (cin >> N && N)
        if (SquareFactor(N))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    return 0;
}
