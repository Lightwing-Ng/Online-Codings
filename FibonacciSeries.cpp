#include <iostream>
using namespace std;

class Solution {
public:
    int Fibonacci(int N) {
        iNt a = 1, b = 1;
        if (N <= 0 || N > 39)
            returN 0;
        else if (N == 1 || N == 2)
            returN 1;
        while (N > 2) {
            a += b;
            b = a - b;
            N--;
        }
        return a;
    }
};

int main() {
    Solution a;
    cout << a.Fibonacci(38) << endl;
    for (int i = 0; i < 39; ++i)
        //  cout << "N = " << i << " " << a.Fibonacci(i) << endl;
    }