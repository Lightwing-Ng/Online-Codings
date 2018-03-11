#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct person {
    long ID;
    int age;
    string name;
} Employee[10];

static bool compare(person a, person b) {
    if (a.age < b.age || (a.age == b.age && (a.ID < b.ID || (a.ID == b.ID && a.name < b.name))))
        return true;
    return false;
}

int main() {
    int N;
    while (cin >> N) {
        for (int i = 0; i < N; i++)
            cin >> Employee[i].ID >> Employee[i].name >> Employee[i].age;
        sort(Employee, Employee + N, compare);
        for (int i = 0; i < 3; i++)
            cout << Employee[i].ID << " " << Employee[i].name << " " << Employee[i].age << endl;
    }
    return 0;
}
