#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N && N) {
        int arr[N], temp[N], sum = 0, count = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        for (count = 0;; count++) {
            for (int i = 0; i < N; i++)
                printf("%2d  ", arr[i]);
            cout << endl;
            for (int i = 0; i < N; i++) //先计算每一轮开始前小朋友要分出（保留的）糖果数
                if (arr[i] % 2 == 1) {  //若为奇数，会造成老师多发一颗糖果补齐为偶数
                    sum += 1;           //用于流动的糖果总数加1
                    temp[i] = (arr[i] + 1) / 2;
                } else //偶数则直接计算发出和留下的
                    temp[i] = arr[i] / 2;

            arr[0] = temp[0] + temp[N - 1]; //头号小朋友情况特殊，单独计算
            for (int i = 1; i < N; i++)     //计算除头号小朋友之外的所分配后得到的糖果总数
                arr[i] = temp[i] + temp[i - 1];
            int flag = 0; //假定全相等为0，不全相等则为1
            for (int i = 1; i < N; i++) //检查是否互为相等，遍历C(N, 2)次
                for (int j = 0; j <= i; j++)
                    if (arr[i] != arr[j])
                        flag = 1;
            if (!flag) //若全等，即flag = 0退出循环
                break;
        }
        cout << count << " " << arr[0] << endl;
    }
    return 0;
}
