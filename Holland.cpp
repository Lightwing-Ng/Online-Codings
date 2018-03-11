class Holland {
public:
    void Sort(int *a) {
        int begin = 0, current = 0, end = a.size() - 1;
        while (current <= end)
            if (a[current] == 0) {
                swap(a[current], a[begin]);
                ++current;
                ++begin;
            } else if (a[current] == 1)
                ++current;
            else {
                swap(a[current], a[end]);
                --end;
            }
    }
private:
    int *a = a[10];
};