#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  priority_queue<int> pq;
  while (t--) {
    int e;
    cin >> e;
    pq.push(e);
    if (pq.size() >= 3) {
      int first = pq.top();
      pq.pop();
      int second = pq.top();
      pq.pop();
      int third = pq.top();
      pq.pop();

      cout << 1LL * first * second * third << endl;

      pq.push(first);
      pq.push(second);
      pq.push(third);
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}