#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<string> v;
  int m = n + 1;
  while (m--) {
    string e;
    cin >> e;
    v.push_back(e);
  }

  string password = v[n];
  int best = 0, worst = 0, lessThan = 0, equal = 0;

  for (int i = 0; i < n; i++) {
    if (v[i].size() < password.size()) {
      lessThan++;
    }
    if (v[i].size() == password.size()) {
      equal++;
    }
  }

  best = lessThan + (lessThan / k) * 5;
  worst = equal + lessThan + ((equal + lessThan - 1) / k) * 5;

  cout << best + 1 << " " << worst << endl;

  return 0;
}