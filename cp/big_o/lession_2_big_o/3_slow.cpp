#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> arr;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    int total = 0;
    int j = i;

    // loop to the beginning: O(n^2)
    while (total + arr[j] < t && j >= 0) {
      total += arr[j];
      j--;
    }
    res = max(res, i - j);
  }

  cout << res << endl;

  return 0;
}