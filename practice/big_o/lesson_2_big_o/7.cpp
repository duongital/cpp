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

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) continue;
    int j = i;
    while (arr[i] > 0 && j >= 0) {
      if (j > 0) {
        arr[j - 1] = -1;
      }
      j--;
      arr[i]--;
    }
  }

  for (int i : arr) {
    if (i >= 0) count++;
  }
  cout << count << endl;

  return 0;
}