#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N && N) {
        int arr[N], sum = 0;
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        sort(arr, arr + N);
        for (int i = 1, temp = arr[0]; i < N; i++, sum += temp)
            temp += arr[i];
        cout << sum << endl;
    }
    return 0;
}
