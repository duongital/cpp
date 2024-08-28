// Fibsieve Fantabulous
// check cases if else
// or there is a solution using bitwise

#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned long long k, m, x, f;

  int t;
  cin >> t;
  int atCase = 1;

  while (t--) {
    cin >> k;
    x = ceil(sqrt(k));
    switch (k) {
      case 1:
        cout << "Case " << atCase++ << ": " << 1 << " " << "1\n";
        break;
      case 2:
        cout << "Case " << atCase++ << ": " << 1 << " " << "2\n";
        break;
      case 3:
        cout << "Case " << atCase++ << ": " << 2 << " " << "2\n";
        break;
      case 4:
        cout << "Case " << atCase++ << ": " << 2 << " " << "1\n";
        break;
    }

    if (x % 2 == 1) {
      m = (x - 1) * (x - 1);

      if (m + x >= k) {
        f = k - m;
        cout << "Case " << atCase++ << ": " << x << " " << f << "\n";
      } else {
        m = x * x;
        f = m - k;
        f++;
        cout << "Case " << atCase++ << ": " << f << " " << x << "\n";
      }

    } else {
      m = (x - 1) * (x - 1);

      if (m + x >= k) {
        f = k - m;
        cout << "Case " << atCase++ << ": " << f << " " << x << "\n";
      } else {
        m = x * x;
        f = m - k;
        f++;
        cout << "Case " << atCase++ << ": " << x << " " << f << "\n";
      }
    }
  }
}