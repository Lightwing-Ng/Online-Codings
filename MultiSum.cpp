#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int a[10];
    while (cin >> a[0]) { //首先输入一个数，即a[0].
        for (int i = 1; i < 10; i++)
            cin >> a[i];
        sort(a, a + 10, cmp); //直接应用排序进行运算。
        cout << "max=" << *a << endl;
    }
}

/*
#include <iostream>
using namespace std;

long long GenerateNumber(int A, int N) {
    long long result = 0;
    int temp = 1;
    for (int i = 0; i < N; i++) {
        result += temp * A;
        temp *= 10;
    }
    return result;
}

int main() {
    int A, N;
    while (cin >> A >> N) {
        long long sum = 0;
        for (int i = 1; i <= N; i++) {
            cout << GenerateNumber(A, i) << endl;
            sum += GenerateNumber(A, i);
        }
        cout << sum << endl;
    }
    return 0;
}
*/
