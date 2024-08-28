#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, N, Q;
  int t = 1;
  vector<int> a;

  while (true) {
    cin >> N >> Q;

    if (N == 0 && Q == 0) {
      break;
    }

    a.resize(N);

    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    cout << "CASE# " << t++ << ":" << endl;

    for (int i = 0; i < Q; i++) {
      cin >> x;
      int index = lower_bound(a.begin(), a.end(), x) - a.begin();

      if (index == N || a[index] != x) {
        cout << x << " not found" << endl;
      } else {
        cout << x << " found at " << index + 1 << endl;
      }
    }
  }

  return 0;
}