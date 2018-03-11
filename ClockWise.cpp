#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> res;
        if (row == 0 || col == 0)
            return res;
        int left = 0, top = 0, right = col - 1, bottom = row - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i)
                res.push_back(matrix[top][i]);
            for (int i = top + 1; i <= bottom; ++i)
                res.push_back(matrix[i][right]);
            if (top != bottom)
                for (int i = right - 1; i >= left; --i)
                    res.push_back(matrix[bottom][i]);
            if (left != right)
                for (int i = bottom - 1; i > top; --i)
                    res.push_back(matrix[i][left]);
            left++, top++, right--, bottom--;
        }
        return res;
    }
};