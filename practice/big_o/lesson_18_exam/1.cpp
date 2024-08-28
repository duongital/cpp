// MUH and Important Things
// list of pairs to count and check duplication

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, c = 0;
  cin >> n;
  pair<int, int> a[2005];
  // create a list of pairs, then add index on second value
  for (int i = 0; cin >> a[i].first; i++) a[i].second = i;

  // sort asc order
  sort(a, a + n);

  for (int i = 0; i + 1 < n; i++) {
    if (a[i].first == a[i + 1].first) c++;

    // if there are two times repeated then found the solution
    if (c == 2) {
      cout << "YES" << endl;
      for (int j = 0; j < n; j++) cout << a[j].second + 1 << " ";
      cout << endl;
      for (int j = 0; j + 1 < n; j++) {
        if (a[j].first == a[j + 1].first) {
          c++;
          swap(a[j].second, a[j + 1].second);
          for (int k = 0; k < n; k++) cout << a[k].second + 1 << " ";
          cout << endl;
          swap(a[j].second, a[j + 1].second);
        }
      }
      return 0;  // found the solution
    }
  }

  cout << "NO" << endl;  // not found the solution
  return 0;
}