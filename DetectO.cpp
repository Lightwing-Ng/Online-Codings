#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

class Bomb {
public:
  void printBomb() {
    for (int i = 1; i < 10; i++) {
      for (int j = 1; j < 10; j++)
        cout << a[i][j] << " ";
      cout << endl;
    }
  }

  void makeBomb() {
    srand((int)time(0));
    while (torpedo > 0) {
      int x = (rand() % (9 - 1 + 1)) + 1;
      int y = (rand() % (9 - 1 + 1)) + 1;
      if (disBomb[x][y] != 1) {
        disBomb[x][y] = 1;
        torpedo--;
      }
    }
  }

  int countBomb(int x, int y) {
    int total = 0;
    if (disBomb[x - 1][y - 1] && disBomb[x - 1][y - 1] == 1)
      total++;
    if (disBomb[x][y - 1] && disBomb[x][y - 1] == 1)
      total++;
    if (disBomb[x + 1][y - 1] && disBomb[x + 1][y - 1] == 1)
      total++;
    if (disBomb[x - 1][y] && disBomb[x - 1][y] == 1)
      total++;
    if (disBomb[x + 1][y] && disBomb[x + 1][y] == 1)
      total++;
    if (disBomb[x - 1][y + 1] && disBomb[x - 1][y + 1] == 1)
      total++;
    if (disBomb[x][y + 1] && disBomb[x][y + 1] == 1)
      total++;
    if (disBomb[x + 1][y + 1] && disBomb[x + 1][y + 1] == 1)
      total++;
    a[x][y] = total;
    return total;
  }

  void GameOver() {
    for (int i = 1; i < 10; ++i) {
      for (int j = 1; j < 10; ++j)
        cout << disBomb[i][j];
      cout << endl;
    }
  }
  int torpedo;
  bool flag;
  int disBomb[10][10], a[10][10];
};

int main() {
  Bomb a;
  a.torpedo = 10;
  a.flag = true;
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      a.disBomb[i][j] = 0;
      cout << a.disBomb[i][j];
    }
    cout << endl;
  }
  a.makeBomb();
  while (a.flag) {
    int X, Y;
    cout << "Please input x and y:\n";
    cin >> X >> Y;
    
    if (!a.disBomb[X][Y]) {
      a.countBomb(X, Y);
      a.printBomb();
    } else {
    	cout << "Sorry that game is over!\n";
      a.GameOver();
      a.flag = false;
    }
  }
}