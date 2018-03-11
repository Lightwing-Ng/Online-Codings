#include <iostream>
#include <memory.h>
using namespace std;

int degree[1005], father[1005];
int findFather(int x) {
    if (x != father[x])
        father[x] = findFather(father[x]);
    return father[x];
}
void Union(int x, int y) {
    int fx = findFather(x), fy = findFather(y);
    if (fx != fy)
        father[fy] = fx;
}

int main(void) {
    int N, M, x, y;
    while (cin >> N >> M && N) {
        memset(degree, 0, sizeof(degree));
        for (int i = 1; i <= N; ++i)
            father[i] = i;
        for (int i = 0; i < M; ++i) {
            cin >> x >> y;
            degree[x]++, degree[y]++;
            Union(x, y);
        }
        bool isEuler = true;
        for (int i = 1; i <= N; ++i)
            if (degree[i] & 1) {
                isEuler = false;
                break;
            }
        if (isEuler) {
            for (int i = 1; i <= N; ++i)
                findFather(i);
            int f = father[1];
            for (int i = 2; i <= N; ++i)
                if (father[i] != f && father[i] != i) {
                    isEuler = false;
                    break;
                }
        }
        printf("%d\n", isEuler ? 1 : 0);
    }
    return 0;
}
