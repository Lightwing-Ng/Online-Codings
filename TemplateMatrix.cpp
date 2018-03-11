/*用c语言中的函数递归调用算法实现n阶矩阵的n次幂*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//创建矩阵，矩阵用一维数组存储
double *matCreate(unsigned int m, unsigned int n) {
    double *p = (double *)malloc(sizeof(double) * m * n);
    if (p == NULL)
        printf("创建矩阵失败！\n");
    return p;
}
//输入矩阵元素
void matInput(double *a, unsigned int m, unsigned int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf ", &a[i * n + j]);
        }
    }
    return;
}
//随机产生矩阵元素，均匀分布于[from to]
void matInitRand(double *a, unsigned int m, unsigned int n, double from, double to) {
    if (a == NULL || m <= 0 || n <= 0)
        return;
    double x;
    srand(time(NULL));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            x = (1.0 * rand()) * (to - from) + from;
            a[i * n + j] = x;
        }
    }
    return;
}
//转置
void matTranspose(double *a, double *b, unsigned int m, unsigned int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            b[j * n + i] = a[i * n + j];
        }
    }
}
//输出矩阵
void matPrint(double *a, unsigned int m, unsigned int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%8.4f ", a[i * n + j]);
        }
        putchar('\n');
    }
    return;
}
//矩阵乘法c=a*b
void matMul(double *a, double *b, double *c, unsigned int m, unsigned int n, unsigned int k) {
    if (a == NULL || b == NULL || c == NULL || m <= 0 || n <= 0 || k <= 0)
        return;
    double x = 0.0f;
    for (int i = 0; i < m; ++i) {
        for (int u = 0; u < k; ++u) {
            x = 0.0f;
            for (int j = 0; j < n; ++j) {
                x += a[i * n + j] * b[j * k + u];
            }
            c[i * k + u] = x;
        }
    }
    return;
}
// b=a^n, a:m*m阶矩阵
void matFac(double *a, double *b, unsigned int n, unsigned int m) {
    double *c = (double *)malloc(sizeof(double) * m * m); //保存临时结果
    if (n > 1) {
        matFac(a, c, n - 1, m);
        matMul(a, c, b, m, m, m);
    } else
        memcpy(b, a, sizeof(double) * m * m);
    free(c); //回收内存
    return;
}

#define M 3
#define N 4
#define K N
int main(int argc, char const *argv[]) {
    double *A, *B, *B1, *BT, *C;
    A = matCreate(M, N);
    B = matCreate(N, K);
    B1 = matCreate(N, K);
    BT = matCreate(K, N);
    C = matCreate(M, K);
    if (!A || !B || !B1 || !BT || !C)
        return -1;
    matInitRand(A, M, N, 0.0f, 1.0f);
    printf("A=\n");
    matPrint(A, M, N);
    matInitRand(B, N, K, 0.0f, 1.0f);
    printf("B=\n");
    matPrint(B, N, K);

    matTranspose(B, BT, N, K);
    printf("B'=\n");
    matPrint(BT, K, N);
    matMul(A, B, C, M, N, K);
    printf("C=A*B\n");
    matPrint(C, M, N);
    matFac(B, B1, 4, N);
    printf("B^4\n");
    matPrint(B1, N, K);
    return 0;
}
