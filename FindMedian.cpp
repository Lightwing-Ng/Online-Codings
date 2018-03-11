#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N && N) {
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        sort(arr, arr + N);
        if (N % 2 == 0)
            cout << (arr[N / 2 - 1] + arr[N / 2]) / 2 << endl;
        else
            cout << arr[N / 2] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int N; cin >> N && N;) {
        vector<int> v(N, 0);
        for (int i = 0; i < N; cin >> v[i++])
            ;
        sort(v.begin(), v.end());
        cout << (N & 1 ? v[N >> 1] : (v[(N >> 1) - 1] + v[N >> 1]) >> 1) << endl;
    }
    return 0;
}
