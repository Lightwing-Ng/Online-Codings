#include <iostream>
#include <string>
using namespace std;

int str2num(string X) {
    int numerical = 0, DECIMAL = 1;
    for (int i = X.size() - 1; i >= 0; i--)
        if (X[i] != ',' && X[i] != '-') {
            numerical += DECIMAL * (X[i] - 48);
            DECIMAL *= 10;
        } else if (X[i] == '-')
            numerical = -numerical;
    return numerical;
}

int main() {
    string A, B;
    while (cin >> A >> B)
        cout << str2num(A) + str2num(B)<< endl;
}
