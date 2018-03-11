#include <iostream>
using namespace std;

int main() {
    int K;
    while (cin >> K) {
        int sum = 0, a[K], k[K], max = 0;
        for (int i = 0; i < K; cin >> a[i++]);
        k[0] = 1;
        for (int i = 1; i < K; i++) {
            k[i] = 1;
            for (int j = i - 1; j >= 0; j--)
                if (a[j] >= a[i] && k[j] + 1 > k[i])
                    k[i] = k[j] + 1;
        }
        for (int i = 0; i < K; i++)
            if (k[i] > max)
                max = k[i];
        cout << max << endl;
    }
}
