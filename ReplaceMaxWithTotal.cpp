#include <iostream>
using namespace std;
int main() {
    int M, N; //定义行列
    while (cin >> M >> N) {
        int content[M][N];
        for (int i = 0; i < M; i++) //输入数组
            for (int j = 0; j < N; j++)
                cin >> content[i][j];
        int MaxInRow[M], RecordCol[M], SumRow[M]; //分别为第i（i <= M - 1）行所对应的最大值，最大值所在列号j（j <= N - 1）,和
        for (int i = 0; i < M; i++) {
            MaxInRow[i] = content[i][0]; //暂取每行的第一个值为改行最大值
            SumRow[i] = 0;
            RecordCol[i] = 0; //一定要初始化为0
            for (int j = 0; j < N; j++) {
                SumRow[i] += content[i][j]; //每行求和
                if(content[i][j] > MaxInRow[i]) { //若改值大于所假定的最大值，替换并记录列号存储于RecordCol[i]
                    MaxInRow[i] = content[i][j];
                    RecordCol[i] = j;
                }
            }
        }
        
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (j == RecordCol[i]) //若列号j和所记录的一致
                    content[i][j] = SumRow[i];
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << content[i][j];
                if (j != N - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
