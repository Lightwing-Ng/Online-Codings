#include <algorithm>
#include <iostream>
using namespace std;

inline int Check(const int *q, const int &key, int size) {
    int left = 0, right = size - 1, mid = (right >> 1);
    while (q[mid] != key) {
        if (q[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
        mid = ((left + right) >> 1);
    }
    return (mid + 1);
}

int main(void) {
    int N;
    while (cin >> N) {
        int arr_1[N], arr_2[N], q[N], i, j;
        for (i = 0; i < N; ++i) {
            cin >> arr_1[i];
            arr_2[i] = arr_1[i];
        }
        sort(arr_1, arr_1 + N);
        for (j = i = 0; i < N; ++i)
            if (i + 1 < N && arr_1[i] != arr_1[i + 1])
                q[j++] = arr_1[i];
            else if (i + 1 == N)
                q[j++] = arr_1[i];
        for (i = 0; i < N - 1; ++i)
            cout << Check(q, arr_2[i], j) << " ";
        cout << Check(q, arr_2[i], j) << "\n";
    }
    return 0;
}
