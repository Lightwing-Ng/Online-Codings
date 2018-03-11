class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> a) {
        vector<int> result;
        result.clear();
        int row = a.size(), col = a[0].size();
        int circleTimes = ((row < col ? row : col) - 1) / 2 + 1;
        for (int i = 0; i < circleTimes; ++i) {
            for (int j = i; j <= col - i - 1; result.push_back(a[i][j++]));
            for (int k = i + 1; k <= row - i - 1; result.push_back(a[k++][col - i - 1]));
            int m = col - i - 2;
        	while (m >= i && row - i - 1 != i)
        		result.push_back(a[row - i - 1][m--]);
        	int n = row - i - 2;
        	while (n > i && col - i - 1 != i)
        		result.push_back(a[n--][i]);
        }
        return result;
    }
};