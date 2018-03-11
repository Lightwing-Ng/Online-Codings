#include <iostream>
using namespace std;

int DigitSum(int N) {
    int sum = 0;
    while (N) {
        sum += N % 10;
        N /= 10;
    }
    return sum;
}

int SquareSum(int N) {
    int sum = 0, square = N * N;
    while (square) {
        sum += square % 10;
        square /= 10;
    }
    return sum;
}

int main() {
    int N;
    while (cin >> N && N)
        cout << DigitSum(N) << " " << SquareSum(N) << endl;
    return 0;
}
