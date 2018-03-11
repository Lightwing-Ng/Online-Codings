#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > a) {
        if (a.empty())
            return false;
        int length = a.size();
        for (int i = 0; i < length; ++i) {
            if (a[i].empty())
                continue;
            else if (target >= a[i][0])
                if (target <= a[i][a[i].size() - 1])
                    for (int j = a[i].size() - 1; j >= 0; --j)
                        if (target == a[i][j])
                            return true;
                        else
                            break;
                else
                    continue;
            else
                return false;
        }
        return false;
    }
};

int main() {
    vector<vector<int> > a;
    vector<int> v;
    int n, temp;
    cin >> n;
    a.clear();
    for (int i = 0; i < n; ++i) {
        v.clear();
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            v.push_back(temp);
        }
        a.push_back(v);
    }
    Solution sample;
    for (int i = 0; i < 100; ++i)
        cout << sample.Find(i, a) << endl;
}