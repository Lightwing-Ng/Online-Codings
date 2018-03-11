#include <iostream>
using namespace std;

int Tree[1000];
int FindRoot(int point) {
    if (Tree[point] == -1)
        return point;
    else
        return FindRoot(Tree[point]);
}

int main() {
    int N, M, point_1, point_2;
    while (cin >> N >> M && N) {
        for (int i = 1; i <= N; i++) //将1号点到N号点赋值为-1，即Tree[i] = -1表示i点孤立
            Tree[i] = -1;
        for (int i = 0; i < M; i++) {  //通过M次循环，若i点与j连通，标记为Tree[i] = j, 1 <= i <= N
            cin >> point_1 >> point_2; //输入首尾相连的两点点号
            point_1 = FindRoot(point_1);
            point_2 = FindRoot(point_2);
            if (point_1 != point_2)
                Tree[point_1] = point_2;
        }
        int count = 0; //计数Tree[i] = -1的点数
        for (int i = 1; i <= N; i++)
            if (Tree[i] == -1)
                count++;
        if (count == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
