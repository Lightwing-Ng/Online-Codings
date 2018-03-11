#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int arr[N], x, i;
        for (i = 0; i < N; i++)
            cin >> arr[i];
        cin >> x;
        for (i = 0; i < N; i++)
            if (x == arr[i]) {
                cout << i << endl;
                break;
            }
        if (i >= N)
            cout << "-1" << endl;
    }
}

/*
#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int a[N], min_index = 0, max_index = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            if (a[min_index] > a[i])
                min_index = i;
            if (a[max_index] < a[i])
                max_index = i;
        }
        int temp = a[min_index];
        a[min_index] = a[max_index];
        a[max_index] = temp;
        for (int i = 0; i < N; i++) {
            cout << a[i];
            if (i != N - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
    return 0;
}
*/
