#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  map<string, int> m;

  cin >> N;
  getchar();
  while (N--) {
    string penguin;
    getline(cin, penguin);
    m[penguin] += 1;
  }

  int best = 0;
  string bestPen = "";
  for (const auto& e : m) {
    if (e.second > best) {
      best = e.second;
      bestPen = e.first;
    }
  }

  cout << bestPen << endl;

  return 0;
}