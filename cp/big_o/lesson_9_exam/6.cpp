#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int count = 0;
  for (char c : s) {
    if (c >= 65 && c <= 90) count++;
  }

  cout << count + 1 << endl;
  return 0;
}