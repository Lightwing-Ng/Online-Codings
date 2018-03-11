#include <iostream>
using namespace std;

int main() {
    int T, M;
    while (cin >> T >> M) {
        int time[M + 1], value[M + 1], f[M + 1][T + 1];
        for (int i = 0; i < M + 1; i++)
            for (int j = 0; j < T + 1; f[i][j++])
                for (int i = 1; i <= M; i++)
                    cin >> time[i] >> value[i];
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= T; j++)
                if (j < time[i])
                    f[i][j] = f[i - 1][j];
                else {
                    int x = f[i - 1][j];
                    int y = f[i - 1][j - time[i]] + value[i];
                    f[i][j] = x < y ? y : x;
                }
        cout << f[M][T] << endl;
    }
}
/*
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, M;
    while (cin >> T >> M) {
        vector<int> cost(M), price(M);
        for (int i = 0; i < M; cin >> cost[i++] >> price[(i++) - 1]);
        vector<int> dp(T + 1, 0);
        for (int i = 0; i < M; i++)
            for (int j = T; j >= cost[i]; j--)
                dp[j] = max(dp[j], dp[j - cost[i]] + price[i]);
        cout << dp[T] << endl;
    }
}
*/
