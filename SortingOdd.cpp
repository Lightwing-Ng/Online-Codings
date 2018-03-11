#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a[10], even[10], odd[10];
    while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >> a[9]) {
        int count_odd = 0, count_even = 0;
        for (int i = 0; i < 10; i++)
            if (a[i] % 2 == 1) {
                odd[count_odd] = a[i];
                count_odd++;
            } else if (a[i] % 2 == 0) {
                even[count_even] = a[i];
                count_even++;
            }

        sort(odd, odd + count_odd), sort(even, even + count_even);
        for (int i = count_odd - 1; i >= 0; i--)
            cout << odd[i] << " ";
        for (int i = 0; i < count_even; i++) {
            cout << even[i];
            if (i != count_even - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
    return 0;
}
