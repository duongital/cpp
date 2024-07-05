#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> cardList;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cardList.push_back(x);
  }

  int i = 0, j = n - 1;
  int player1 = 0, player2 = 0;
  bool isPlayer1 = true;
  while (i <= j) {
    if (cardList[i] < cardList[j]) {
      if (isPlayer1) {
        player1 += cardList[j];
      } else {
        player2 += cardList[j];
      }
      j--;

    } else {
      if (isPlayer1) {
        player1 += cardList[i];
      } else {
        player2 += cardList[i];
      }
      i++;
    }
    isPlayer1 = !isPlayer1;
  }

  cout << player1 << " " << player2 << endl;

  return 0;
}