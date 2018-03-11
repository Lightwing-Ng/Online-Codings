class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.size() == 0)
            return;
        int i = 0;
        while (i < array.size()) {
            while (i < array.size() && array[i] % 2 != 0)
                i++;
            int j = i;
            while (j < array.size() && array[j] % 2 == 0)
                j++;
            if (j == array.size())
                break;
            int temp = array[j];
            for (int k = j; k > i; k--)
                array[k] = array[k - 1];
            array[i] = temp;
        }
    }
};