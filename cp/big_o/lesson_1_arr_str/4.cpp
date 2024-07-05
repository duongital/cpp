#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  string t;
  cin >> t;

  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == 'z') {
      s[i] = 'a';
    } else {
      s[i] = s[i] + 1;
      break;
    }
  }

  if (s == t) {
    cout << "No such string" << endl;
  } else {
    cout << s << endl;
  }

  return 0;
}