#include <iostream>
using namespace std;

int isSimplestProperFraction(int n, int m) {
    int rest = 1;
    if (m > n) {
        while (rest) {
            rest = m % n;
            m = n;
            n = rest;
        }
        if (m == 1)
        	return 1; 
    }
    return 0;
}

int main() {
	int N;
	while (cin >> N && N) {
		int arr[N], count = 0;
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
                if (i != j && isSimplestProperFraction(arr[j], arr[i]))
                	count++;
        cout << count << endl;
	}
    return 0;
}
