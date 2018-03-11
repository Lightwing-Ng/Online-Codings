#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        vector<int> temp; //定义一向量容器temp用以存储二进制位数
        vector<int>::iterator it; //定义迭代器it用以遍历容器内的元素
        for (int i = 0; i < N; i++) {
            while (arr[i]) {
                temp.push_back(arr[i] % 2);
                arr[i] /= 2;
            }
            for (it = temp.end() - 1; it != temp.begin() - 1; it--)
                cout << *it;
            cout << endl;
            temp.clear();
        }
    }
    return 0;
}
