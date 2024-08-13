#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    int n, m;
    cin >> n >> m;

    set<long long> s;
    while (n--) {
      long long e;
      cin >> e;
      s.insert(e);
    }

    while (m--) {
      long long e;
      cin >> e;

      set<long long>::iterator it;
      it = s.find(e);
      if (it != s.end()) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
        s.insert(e);
      }
    }
  }
  return 0;
}