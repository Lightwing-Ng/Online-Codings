#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int flag = 0;
        for (int i = 2; i <= sqrt(N); i++)
            if (N % i == 0)
                flag = 1;
        if (N == 1 || flag)
            cout << "no" << endl;
        else if (N == 2 || !flag)
            cout << "yes" << endl;
    }
    return 0;
}
