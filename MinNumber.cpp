#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int arr[N][2];
        for (int i = 0; i < N; i++)
            cin >> arr[i][0] >> arr[i][1];
        int x_min = arr[0][0], y_min = arr[0][1];
        for (int i = 0; i < N; i++)
            if (x_min > arr[i][0]) {
                x_min = arr[i][0];
                y_min = arr[i][1];
            } else if (x_min == arr[i][0] && y_min > arr[i][1])
                y_min = arr[i][1];
        cout << x_min << " " << y_min << endl;
    }
    return 0;
}
