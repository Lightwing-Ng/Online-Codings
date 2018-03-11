#include <algorithm>
#include <iostream>
using namespace std;

struct rats {
    string color;
    int weight;
} a[1000];

static bool cmp(rats a, rats b) {
    if (a.weight > b.weight)
        return true;
    return false;
}

int main(void) {
    int N;
    while (cin >> N && N) {
        for (int i = 0; i < N; i++)
            cin >> a[i].weight >> a[i].color;
        sort(a, a + N, cmp);
        for (int i = 0; i < N; cout << a[i++].color << endl);
    }
    return 0;
}
