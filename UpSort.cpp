#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        sort(arr, arr + N);
        for (int i = 0; i < N; i++) {
            cout << arr[i];
            if (i != N - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
