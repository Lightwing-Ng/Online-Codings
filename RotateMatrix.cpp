#include <iostream>
using namespace std;

int main() {
    int arr[6][6] = { 0 }, temp[3][3] = { 0 };
    int angle = 0, size = 0, x = 0, y = 0;
    while (cin >> arr[1][1] >> arr[1][2] >> arr[1][3] >> arr[1][4] >> arr[1][5]) {
        for (int i = 2; i < 6; i++)
            for (int j = 1; j < 6; j++)
                    cin >> arr[i][j];
        cin >> angle >> size >> x >> y;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (angle == 1)
                    temp[j][size - i - 1] = arr[x + i][y + j];
                else
                    temp[size - j - 1][i] = arr[x + i][y + j];
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                arr[x + i][y + j] = temp[i][j];
        for (int i = 1; i < 6; ++i)
            for (int j = 1; j < 6; ++j) {
                cout << arr[i][j];
                if (j != 5)
                    cout << " ";
                else
                    cout << endl;
            }
    }
    return 0;
}
