#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        for (int k = 0; k < N; k++) {
            int input[4][5], result[2][5];

            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 5; j++)
                    cin >> input[i][j];

            for (int j = 0; j < 5; j++) {
                int max_1 = input[0][j], max_2 = input[1][j];
                for (int i = 2; i < 4; ++i) {
                    if (input[i][j] > max_1) {
                        if (max_1 > max_2)
                            max_2 = input[i][j];
                        else {
                            max_1 = max_2;
                            max_2 = input[i][j];
                        }
                    } else if (input[i][j] > max_2)
                        max_2 = input[i][j];
                }
                result[0][j] = max_1;
                result[1][j] = max_2;
            }
            
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 5; j++)
                    cout << result[i][j] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}

/*
 从1,000,000中找出前K个数
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10000;
const int K = 100;

void AdjustDown(int topK[], int size, size_t parent) {
    assert(topK);
    int child = parent * 2 + 1;
    while (child < size) {
        if (child + 1 < size && topK[child + 1] < topK[child])
            ++child;
        if (topK[child] < topK[parent]) {
            swap(topK[child], topK[parent]);

            parent = child;
            child = parent * 2 + 1;
        } else
            break;
    }
}

void GetTopKValue(int array[], int topK[]) {
    assert(K < N);
    for (int i = 0; i < K; ++i)
        topK[i] = array[i];
    for (int i = (K - 2) / 2; i >= 0; --i)
        AdjustDown(topK, K, i);

    for (int i = K; i < N; ++i)
        if (array[i] > topK[0]) {
            topK[0] = array[i];
            AdjustDown(topK, K, 0);
        }
    for (int i = 0; i < K; ++i) {
        cout << endl;
        if (i % 5 == 0)
            cout << endl;
    }
    cout << endl;
}

void Test() {
    int array[N] = { 0 }, topK[K] = { 0 };
    for (int i = 0; i < N; ++i)
        array[i] = i;
    array[9] = 111111;
    array[99] = 1111111;
    array[999] = 11111111;
    GetTopKValue(array, topK);
}

int main() {
    Test();
    return 0;
}

*/
