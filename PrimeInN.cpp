#include <iostream>
#include <math.h>
using namespace std;

int isPrime(int N) {
    int flag = 1, end = sqrt(N);
    for (int i = 2; i <= end; i++)
        if (N % i == 0)
            flag = 0;
    return flag;
}

int main() {
    int N;
    while (cin >> N) {
        int count = 0, arr[1000];
        for (int i = 2; i <= N; i++)
            if (isPrime(i) && i % 10 == 1 && i != N) {
                arr[count] = i;
                count++;
            }
        for (int i = 0; i < count; i++) {
            cout << arr[i];
            if (i != count - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
    return 0;
}
