class Solution {
private:
    int count = 0;
    int sum(int N) {
        int result = 0;
        while (N) {
            result += N % 10;
            N /= 10;
        }
        return result;
    }
public:
    bool valid(int i, int j, int th) {
        int res = sum(i) + sum(j);
        return res <= th;
    }

    void DFS(int th, int rows, int cols, int i, int j, bool **blank) {
        if (i >= 0 && i < rows && j >= 0 && j < cols && !blank[i][j] && valid(i, j, th)) {
            ++ count;
            blank[i][j] = true;
            DFS(th, rows, cols, i - 1, j, blank);
            DFS(th, rows, cols, i + 1, j, blank);
            DFS(th, rows, cols, i, j - 1, blank);
            DFS(th, rows, cols, i, j + 1, blank);
        }
    }

    int movingCount(int threshold, int rows, int cols) {
        if (rows < 1 || cols < 1 || threshold < 0)
            return 0;

        bool **blank = new bool* [rows];
        for (int i = 0; i < rows; i++)
            blank[i] = new bool[cols] {false};
        
        DFS(threshold, rows, cols, 0, 0, blank);
        return count;
    }
};