#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int SquareNumber = N * N, arr[5], index;
        for (int i = 0; i < 5; i++) {
            arr[i] = SquareNumber % 10;
            SquareNumber /= 10;
            index = i;
        }
        index--;
        int temp = 0, TEN = 1, flag = 0;
        for (int i = 0; i < index - 1; i++) {
            temp += TEN * arr[i];
            TEN *= 10;
            if (temp == N) {
                cout << "Yes!" << endl;
                flag = 1;
            }
        }
        if (!flag)
            cout << "No!" << endl;
    }
    return 0;
}
