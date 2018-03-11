#include <iostream>
using namespace std;

int main() {
    int N, x, y, z;
    while (cin >> N) {
        for (x = 0; x <= N / 5; x++)
            for (y = 0; y <= (N - 5 * x) / 3; y++)
                for (z = 0; z <= (N - 5 * x - 3 * y) * 3; z++)
                    if (x + y + z == 100)
                        printf("x=%d,y=%d,z=%d\n", x, y, z);
    }
    return 0;
}
