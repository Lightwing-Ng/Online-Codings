#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int N, K;
    while (cin >> N >> K) {
        int sum = 0, flag = 0, count = 0;
        while (count <= 21) {
            sum += N;
            if (sum >= 200 * pow(1 + double(K) / 100, count)) {
                cout << count + 1 << endl;
                flag = 1;
                break;
            }
            count++;
        }
        if (!flag)
            cout << "Impossible" << endl;
    }
    return 0;
}
