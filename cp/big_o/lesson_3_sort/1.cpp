#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> arr;

  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    arr.push_back(e);
  }

  sort(arr.begin(), arr.end());
  // long long total = 0;
  long long total = 0;
  for (int i : arr) {
    total += (long long)i * x;
    if (x > 1) {
      x--;
    }
  }

  cout << total << endl;

  return 0;
}