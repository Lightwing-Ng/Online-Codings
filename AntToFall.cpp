#include <algorithm>
#include <iostream>
#define N 102
using namespace std;

int aa[N], bb[N]; // left蚂蚁位置 right蚂蚁位置
int x[N], s[N];
int main() {
    int n;
    while (cin >> n) {
        int pos = 0; //蚂蚁A位置
        for (int i = 1; i <= n; ++i) {
            cin >> x[i] >> s[i];
            if (s[i] == 0)
                pos = x[i];
        }
        int nl = 0, nr = 0;
        for (int i = 1; i <= n; ++i) {
            if (x[i] < pos && s[i] > 0)
                aa[++nl] = 100 - x[i];
            else if (x[i] > pos && s[i] < 0)
                bb[++nr] = x[i];
        }
        if (nl == nr)
            cout << "Cannot fall!" << endl;
        else if (nl > nr) {
            sort(aa + 1, aa + nl + 1);
            cout << aa[nr + 1] << endl;
        } else {
            sort(bb + 1, bb + nr + 1);
            cout << bb[nl + 1] << endl;
        }
    }
    return 0;
}

/*
#include <iostream>
using namespace std;

struct ant {
    int x, s;
};
int main() {
    int N;
    while (cin >> N && N) {
        ant a[100];
        int flag, seconds = 1, AreOthersFall = 1; //假定其余的蚂蚁都掉了
        for (int i = 0; i < N; i++) {             //对初始变量赋值
            cin >> a[i].x;
            cin >> a[i].s;
            if (a[i].s == 0)
                flag = i;
        }
        while (a[flag].x > 0 && a[flag].x < 100) {
            for (int j = 0; j < N; j++) {
                a[j].x += a[j].s;
                for (int k = 0; k <= j; k++)
                    if (a[k].x == a[j].x && ((a[k].s * a[j].s == -1) || (a[k].s * a[j].s == 0 && a[k].s + a[j].s != 0))) {
                        int temp = a[k].s;
                        a[k].s = a[j].s;
                        a[j].s = temp;
                    }
            }
            seconds++; //从1s开始，未定义结束时刻
            if (a[flag].s == 0) {
                for (int j = 0; j < N; j++)
                    if (a[j].x > 0 && a[j].x < 100 && j != flag)
                        AreOthersFall = 0; //若存在还在范围内的蚂蚁，标记为0
                if (AreOthersFall) {
                    cout << "Cannot fall" << endl;
                    break;
                }
            }
        }
        if (AreOthersFall) //假若蚂蚁能跳出
            cout << seconds << endl;
    }
    return 0;
}
*/
