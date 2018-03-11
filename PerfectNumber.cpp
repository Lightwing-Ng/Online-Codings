#include <iostream>
using namespace std;

int isPerfectNumber(int N) {
    int sum = 0;
    for (int i = 1; i <= N / 2; i++)
        if (N % i == 0)
            sum += i;
    if (N == sum)
        return 1;
    else
        return 0;
}

int main() {
    int N;
    while (cin >> N) {
        int count = 0, arr[5];
        for (int i = 1; i <= N; i++)
            if (isPerfectNumber(i)) {
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
