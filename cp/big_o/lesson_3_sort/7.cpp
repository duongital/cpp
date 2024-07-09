#include <bits/stdc++.h>

using namespace std;

bool callback(int a, int b) {
  if (a > b) return true;
  return false;
}

int main() {
  int k;
  cin >> k;

  vector<int> arr;
  for (int i = 0; i < 12; i++) {
    int e;
    cin >> e;
    arr.push_back(e);
  }

  sort(arr.begin(), arr.end(), callback);
  int sum = 0, index = 0;
  for (int i = 0; i < 12; i++) {
    if (sum < k) {
      sum += arr[i];
      index = i;
    }
  }
  if (k == 0) {
    cout << 0 << endl;
  } else if (sum >= k) {
    cout << index + 1 << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}