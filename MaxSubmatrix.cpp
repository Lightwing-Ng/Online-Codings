#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int A[N][N], max = -100000;
        for (int i = 0; i < N; i++)
            for (int j = 0; j<N; cin>> A[i][j++]); //输入矩阵A[N][N]
        for (int i = 1; i <= N; i++) //遍历(N * N - 1)种子矩阵，每个子矩阵S为i×j
            for (int j = 1; j <= N; j++)
                if (i != N && j != N) //除去子矩阵为本身的情况
                    for (int is = 0; is <= N - i; is++) // 以左上角作为起点(is, js)遍历遍历S(i×j)的所有可能矩阵
                        for (int js = 0; js <= N - j; js++) { //对应i行j列的子矩阵，其左上角坐标范围在[0, N - j]， [0， N - i]
                            int sum = 0;
                            for (int row = is; row < is + i; row++)
                                for (int col = js; col < js + j; col++)
                                    sum += A[row][col];
                            if (sum > max)
                                max = sum;
                        }
        cout << max << endl;
    }
}
