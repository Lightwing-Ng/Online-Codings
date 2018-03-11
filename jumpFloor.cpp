class Solution {
public:
    int rectCover(int N) {
        if (N < 0)
            return -1;
        if (N < 3)
            return N;
        int f = 1, g = 2, cur = 0;
        for (int i = 3; i <= N; ++i) {
            cur = f + g;
            f = g;
            g = cur;
        }
        return cur;
    }
};