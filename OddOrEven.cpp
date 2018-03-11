#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int arr[N], odd = 0, even = 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        cout << even << " " << odd << endl;
        if (even <= odd)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
