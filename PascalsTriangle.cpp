#include <iostream>
using namespace std;

long PascalNumber(int row, int col) {
    if ((row == 2 || row == 1) || (row > 2 && (col == 0 || col == row - 1)))
        return 1;
    else
        return PascalNumber(row - 1, col - 1) + PascalNumber(row - 1, col);
}

int main() {
    int N;
    while (cin >> N)
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                cout << PascalNumber(i, j);
                if (j != i - 1)
                    cout << " ";
            }
            cout << endl;
        }
    return 0;
}
