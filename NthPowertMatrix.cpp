#include <iostream>
using namespace std;

int main() {
    int T;
    while (cin >> T) {
        while (T) { //循环打印T个数组
            int N, K;
            cin >> N >> K;
            int arr[N][N], b[N][N], result[N][N];
            for (int i = 0; i < N; i++) //输入N×N个元素
                for (int j = 0; j < N; j++)
                    cin >> arr[i][j];
            memcpy(result, arr, sizeof(result)); //将第一个结果设为数组本身
            for (int v = 0; v < K - 1; v++) {
                memcpy(b, result, sizeof(b));     //每次运算，都将上一次的结果存为数组b，防止干扰
                for (int i = 0; i < N; i++)       //结果的第i行
                    for (int j = 0; j < N; j++) { //结果的第j列
                        int temp = 0;             //设temp为结果result[i][j]的暂存值
                        for (int u = 0; u < N; u++)
                            temp += arr[i][u] * b[u][j];
                        result[i][j] = temp;
                    }
            }
            for (int i = 0; i < N; i++) //打印结果
                for (int j = 0; j < N; j++) {
                    cout << result[i][j];
                    if (j != N - 1)
                        cout << " ";
                    else
                        cout << endl;
                }
            T--;
        }
    }
    return 0;
}

