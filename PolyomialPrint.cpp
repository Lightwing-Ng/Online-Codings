#include <iostream>
#include <string>
#define SizeMax 2001
using namespace std;

int main() {
    int arr[SizeMax];
    memset(arr, 0, sizeof(int) * SizeMax);
    int N, M, cefc, index, count = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cefc >> index;
        arr[1000 + index] = arr[1000 + index] + cefc;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> cefc >> index;
        arr[1000 + index] = arr[1000 + index] + cefc;
    }

    for (int i = 0; i < SizeMax; i++)
        if (arr[i] != 0)
            count++;

    for (int i = SizeMax - 1; i >= 0; i--)
        if (arr[i] != 0) {
            count--;
            cout << arr[i] << ' ' << i - 1000;
            if (count)
                cout << ' ';
            else
                cout << endl;
        }

    return 0;
}
