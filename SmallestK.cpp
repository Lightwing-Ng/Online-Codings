#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int arr[N], K, count = 0; // count为所有数字总出现的字数，不包括本身
        for (int i = 0; i < N; i++) {
            int temp, flag = 0; // flag为重复标志，每次输入新数字前初始为0
            cin >> temp;        // temp为代查重的临时变量
            if (i >= 1)         //在输入第二及以后的数字开始遍历查重
                for (int j = 0; j < i; j++)
                    if (arr[j] == temp) {
                        flag = 1; //若有重复，标记为1
                        count++;  //重复总数+1
                    }
            if (!flag) //若不重复，计入到arr[i]
                arr[i] = temp;
            else
                arr[i] = 0; //若重复，计为0以便参与排序
        }
        sort(arr, arr + N); //调用STL升序排序
        cin >> K;
        cout << arr[K + count - 1] << endl; //第K小的数即为(K + 总重复次数 - 1)
    }
    return 0;
}

