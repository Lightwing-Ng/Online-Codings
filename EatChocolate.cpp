#include <iostream>
using namespace std;

float credit[10], score[10], grade[10];
int main() {
    float sum = 0, total = 0;
    int N;
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            cin >> credit[i];
            total += credit[i];
        }
        for (i = 0; i < N; i++) {
            cin >> score[i];
            if (score[i] >= 90 && score[i] <= 100)
                grade[i] = 4.0;
            else if (score[i] < 90 && score[i] >= 85)
                grade[i] = 3.7;
            else if (score[i] < 85 && score[i] >= 82)
                grade[i] = 3.3;
            else if (score[i] < 82 && score[i] >= 78)
                grade[i] = 3.0;
            else if (score[i] < 78 && score[i] >= 75)
                grade[i] = 2.7;
            else if (score[i] < 75 && score[i] >= 72)
                grade[i] = 2.3;
            else if (score[i] < 72 && score[i] >= 68)
                grade[i] = 2.0;
            else if (score[i] < 68 && score[i] >= 64)
                grade[i] = 1.5;
            else if (score[i] < 64 && score[i] >= 60)
                grade[i] = 1.0;
            else
                grade[i] = 0;
            sum += grade[i] * credit[i];
        }
        printf("%.2f\n", sum / total);
    }
}
/*
#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N <= 2)
            cout << N << endl;
        else {
            long long x1 = 1, x2 = 2, x3;
            for (int i = 3; i <= N; i++) {
                x3 = x2 + x1;
                x1 = x2;
                x2 = x3;
            }
            cout << x3 << endl;
        }
    }
}
