#include <algorithm>
#include <iostream>
#include <string>
#define StudentMax 1000
using namespace std;

struct person {
    string name;
    int age;
    int score;
} Student[StudentMax];

bool cmp(person a, person b) {
    if (a.score != b.score)
        return a.score < b.score;
    if (a.name != b.name)
        return a.name < b.name;
    else
        return a.age < b.age;
}

int main() {
    int N;
    while (cin >> N) {
        for (int i = 0; i < N; i++)
            cin >> Student[i].name >> Student[i].age >> Student[i].score;
        sort(Student, Student + N, cmp);
        for (int i = 0; i < N; i++)
            cout << Student[i].name << " " << Student[i].age << " " << Student[i].score << endl;
    }
    return 0;
}
