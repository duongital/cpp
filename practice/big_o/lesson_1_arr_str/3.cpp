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

  if (arr[0] > 15) {
    cout << 15 << endl;
    return 0;
  };

  if (n == 1 && arr[0] <= 15) {
    cout << arr[0] + 15 << endl;
    return 0;
  }

  int total = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] - arr[i - 1] <= 15) {
      total = arr[i];
    } else {
      cout << arr[i - 1] + 15 << endl;
      return 0;
    }
  }

  if (total + 15 > 90) {
    cout << 90 << endl;
  } else {
    cout << total + 15 << endl;
  }

  return 0;
}