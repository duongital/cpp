#include <bits/stdc++.h>

using namespace std;

int main() {
  int len;
  cin >> len;

  set<char> s;
  int t = len;
  while (t--) {
    char c;
    cin >> c;
    s.insert(tolower(c));
  }

  if (s.size() == 26) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}