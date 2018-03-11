#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct student {
    string AdmissionID;
    int SolvedNumber, TotalScore;
    vector<int> GotScore;
} examinee[1000];

static bool cmp(student a, student b) {
    if (a.TotalScore > b.TotalScore)
        return true;
    else
        return false;
}

int main() {
    int N, M, G;
    while (cin >> N >> M >> G && N) {
        int SubjectValues[M], count = 0;
        for (int i = 0; i < M; i++) {
            cin >> SubjectValues[i];
        	cout << "SubjectValues[i] = " << SubjectValues[i] << " "     
        }
        for (int i = 0; i < N; i++) {
            cin >> examinee[i].AdmissionID >> examinee[i].SolvedNumber;
            for (i = 0; i < examinee[i].SolvedNumber; i++) {
                int temp;
                cin >> temp;
                examinee[i].GotScore.push_back(temp);
            }
            int sum = 0;
            for (int j = 0; j < examinee[i].SolvedNumber; j++)
            	sum += SubjectValues[examinee[i].GotScore.back() - 1];
            examinee[i].TotalScore = sum;
        }
        sort(examinee, examinee + M, cmp);
        for (int i = 0; i < M; i++)
        	cout << examinee[i].AdmissionID << " " << examinee[i].TotalScore << endl;
    }
    return 0;
}














