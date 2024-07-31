#include <bits/stdc++.h>

using namespace std;

int main() {
  int k, n, w;
  cin >> k >> n >> w;

  int fee = k * w * (w + 1) / 2;
  if (n >= fee) {
    cout << 0 << endl;
  } else {
    cout << fee - n;
  }

  return 0;
}