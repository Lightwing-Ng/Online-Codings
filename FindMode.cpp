#include <iostream>
using namespace std;

int main() {
    int arr[20];
    while (cin >> arr[0]) {
        int count[20] = { 1 }, count_max = 1, flag = 0, mode_min;
        for (int i = 1; i < 20; i++) { //用循环输入arr[1]-arr[19]
            cin >> arr[i];
            for (int j = 0; j <= i; j++) //检测当前输入的arr[i](i >= 1)共重复的次数，并计入count[i]（count[i] >= 1）
                if (arr[j] == arr[i])
                    count[i] += 1;
            if (count[i] > count_max) //找出最大的重复数字
                count_max = count[i];
        }
        for (int i = 0; i < 20; i++)
            if (count[i] == count_max) { //若重复数字与找出的符合
                flag++;
                if (flag == 1) //假定第一个众数为权值最小的
                    mode_min = arr[i];
                else if (arr[i] < mode_min) //如有更小且重复次数相同的数，更新mode_min
                    mode_min = arr[i];
            }
        cout << mode_min << endl;
    }
    return 0;
}
