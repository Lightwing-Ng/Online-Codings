#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int A[N][N], B[N][N], result = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> A[i][j];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> B[i][j];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (result == 0 && A[i][j] == B[i][j])
                    continue;
                else {
                    result = 90;
                    if (result == 90 && (A[i][j] == B[j][N - i - 1]))
                        continue;
                    else {
                        result = 180;
                        if (result == 180 && (A[i][j] == B[N - i - 1][N - j - 1]))
                            continue;
                        else {
                            result = 270;
                            if (result == 270 && (A[i][j] == B[N - j - 1][i]))
                                continue;
                            else {
                                result = -1;
                                break;
                            }
                        }
                    }
                }
            }
        cout << result << endl;
    }
}
