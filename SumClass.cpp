class Solution {
public:
    int Sum_Solution(int N) {
        int result = 0;
        for (int i = 1; i <= N; ++i)
            result += i;
        return result;
    }
};