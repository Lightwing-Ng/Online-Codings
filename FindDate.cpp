#include <iostream>
using namespace std;
int main() {
    int YEAR, N, i;
    int MONTH[13] = { 1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while (cin >> YEAR >> N) {
        if ((YEAR % 4 == 0 && YEAR % 100 != 0) || YEAR % 400 == 0)
            MONTH[2] = 29;
        else
            MONTH[2] = 28;
        for (i = 1; i <= 13; i++) {
            if (N <= MONTH[i]) {
                printf("%d-%02d-%02d\n", YEAR, i, N);
                break;
            } else if (N > MONTH[i])
                N = N - MONTH[i];
        }
    }
}
