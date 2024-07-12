#include <iostream>
#include <queue>

using namespace std;

void throwingCards(int n) {
  queue<int> qu;
  vector<int> discardedCards;

  for (int i = 1; i <= n; i++) {
    qu.push(i);
  }

  while (qu.size() > 1) {
    int toDiscard = qu.front();
    discardedCards.push_back(toDiscard);
    qu.pop();

    int toBottom = qu.front();
    qu.push(toBottom);
    qu.pop();
  }

  cout << "Discarded cards:";
  for (int i = 0; i < discardedCards.size(); i++) {
    cout << " " << discardedCards[i];
    if (i < discardedCards.size() - 1) cout << ",";
  }
  cout << endl;
  cout << "Remaining card: " << qu.front() << endl;
}

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    throwingCards(n);
  }
  return 0;
}