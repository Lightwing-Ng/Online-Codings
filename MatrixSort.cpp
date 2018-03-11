#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int arr[N][N], IndexMax[N], index, temp[N]; //每一列最大值标记IndexMax[N], 最大值所在行数，用于置换的temp
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> arr[i][j];
        
        for (int j = 0; j < N; j++) { //从列到行循环
            IndexMax[j] = arr[j][j];  //先假定j列的j行为最大值，并记录行号index = j
            index = j;
            for (int i = j; i < N; i++) // 行号由j开始到最大值结束
                if (arr[i][j] > IndexMax[j]) { //查找最大值，先进行标记操作
                    IndexMax[j] = arr[i][j];
                    index = i;
                }
            for (int k = 0; k < N; k++) { //循环完后，第j行与index行相互交换
                temp[k] = arr[index][k];
                arr[index][k] = arr[j][k];
                arr[j][k] = temp[k];
            }
        }
        
        for (int i = 0; i < N; i++) { //打印转置以后的数组
            for (int j = 0; j < N; j++) {
                cout << arr[i][j];
                if (j != N - 1) //若不为结尾打印空格以分隔
                    cout << " ";
            }
            cout << endl;
        }
    }
}

