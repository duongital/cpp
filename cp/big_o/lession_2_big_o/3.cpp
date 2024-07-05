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

  int start = 0;
  int time_total = 0;
  int max_book = 0;

  for (int end = 0; end < n; end++) {
    time_total += arr[end];

    // sliding the start pointer, and not depend on n: O(n)
    while (time_total > t) {
      time_total -= arr[start];
      start++;  // no need to care previous start pointer
    }

    // we get time_total <= t here
    max_book = max(max_book, end - start + 1);
  }

  cout << max_book << endl;

  return 0;
}