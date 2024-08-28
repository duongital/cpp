#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int sum = 0;
  string t;
  if (s[0] == 'a') {
    t = s;
  } else {
    t = 'a' + s;
  }

  for (int i = 1; i < t.size(); i++) {
    int gap = abs(t[i] - t[i - 1]);
    if (gap > 13) {
      sum += (26 - gap);
    } else {
      sum += gap;
    }
  }

  cout << sum << endl;

  return 0;
}