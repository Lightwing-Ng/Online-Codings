#include <iostream>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int arr[N][N], flag = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                if ((i >0 && j < i) && arr[i][j] != arr[j][i])
                    flag = 1;
            }
        if (flag)
            cout << "No!" << endl;
        else
            cout << "Yes!" << endl;
    }
    return 0;
}
