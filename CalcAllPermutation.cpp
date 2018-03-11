#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool CalcAllPermutation(char *perm, int num)
{
    int i;
    for (i = num - 2; i >= 0 && perm[i] >= perm[i + 1]; --i);
    if (i < 0)
        return false;
    int k;
    for (k = num - i; k > i && perm[k] <= perm[i]; --k);
    swap(perm[i], perm[k]);
    reverse(perm[i], perm[k]);
    return false;
}

int main()
{
    int a[5] = {2, 1, 5, 4, 3};
}