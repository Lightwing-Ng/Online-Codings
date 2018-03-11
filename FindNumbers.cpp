#include <iostream>
using namespace std;

int main() {
    int N, M, a[100], b[100];
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> b[i];

    for (int j = 0; j < M; j++)
        for (int i = 0; i < N; i++) {
            if (a[i] == b[j]) {
                cout << "YES" << endl;
                break;
            }
            if (i == N - 1 && a[i] != b[j])
                cout << "NO" << endl;
        }
}
