#include <iostream>
using namespace std;

void TwoSum(int a[], unsigned int length, int sum) {
    int begin = 0, end = length - 1;
    while (begin < end) {
        long currSum = a[begin] + a[end];
        if (currSum == sum) {
            cout << a[begin] << " " << a[end] << endl;
            break;
        } else {
            if (currSum < sum)
                begin++;
            else
                begin--;
        }
    }
}

int main() {
    int N;
    cin >> N;
    int a[N], taget;
    for (int i = 0; i < N; cin >> a[i++]);
    cin >> taget;
    for (int i = 0; i < N - 1; ++i)
        for (int j = i + 1; j < N; ++j)
            if (a[i] + a[j] == taget)
                cout << a[i] << " " << a[j] << endl;
    cout << TwoSum(a, 7, 15) << endl;
}