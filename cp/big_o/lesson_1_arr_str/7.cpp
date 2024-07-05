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
  int best = 0, worst = 0, lessThan = 0, lessThanOrEqual = 0;

  for (int i = 0; i < n; i++) {
    if (v[i].size() < password.size()) {
      lessThan++;
    }
    if (v[i].size() <= password.size()) {
      lessThanOrEqual++;
    }
  }

  best = (lessThan / k) * 5 + lessThan;
  worst = (lessThanOrEqual / k) * 5 + lessThanOrEqual;

  cout << best + 1 << " " << worst << endl;

  return 0;
}