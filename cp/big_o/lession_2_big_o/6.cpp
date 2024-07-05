#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int maxLength = 0;
  for (int i = 0; i < n - 1; i++) {
    int minElement = INT_MAX;
    for (int j = i; j < n; j++) {
      minElement = min(minElement, arr[j]);
      if (i == j) continue;
      if (arr[j] - minElement > 1) {
        maxLength = max(maxLength, j - i);
        cout << i << " " << j - 1 << endl;
        minElement = INT_MAX;
        break;
      }
    }
  }

  return 0;
}