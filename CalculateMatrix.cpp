#include <iostream>
using namespace std;

int main() {
    int A[2][3], B[3][2], result[2][2];
    while (cin >> A[0][0] >> A[0][1] >> A[0][2]) {
        for (int i = 1, j = 0; j < 3; j++)
            cin >> A[i][j];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 2; j++)
                cin >> B[i][j];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                int temp = 0;
                for (int u = 0; u < 3; u++)
                    temp += A[i][u] * B[u][j];
                result[i][j] = temp;
            }

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                cout << result[i][j];
                if (j != 1)
                    cout << " ";
                else
                    cout << endl;
            }
    }
    return 0;
}
