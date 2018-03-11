#include <iostream>
using namespace std;

int main() {
    int N, M, books[50000];
    while (cin >> N >> M) {
        int person[201] = { 0 };
        for (int i = 0; i < N; i++) {
            cin >> books[i];
            person[books[i]]++;
        }
        for (int i = 0; i < N; i++)
            if (person[books[i]] > 1)
            	cout << person[books[i]] - 1 << endl;
            else
            	cout << "BeiJu" << endl;
    }
    return 0;
}
/*
#include <iostream>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M && N) {
        int borrower[N + 1];
        for (int i = 1; i <= N; i++)
            cin >> borrower[i];
        for (int i = 1; i <= N; i++) {
            int flag = 0;
            for (int j = 1; j <= N; j++)
                if (i != j && borrower[i] == borrower[j])
                    flag = 1;
            if (flag)
                cout << "1" << endl;
            else
                cout << "BeiJu" << endl;
        }
    }
    return 0;
}
*/
