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

  int t = n - 1, count = 1;
  while (t >= 0) {
    if (arr[t] == 0) {
      // cout << "is zero" << endl;
      if (t + 1 < n && arr[t + 1] == 0) {
        count++;
      }
      t--;
    } else {
      // cout << "is multiple dies" << endl;
      t -= arr[t];
    }
  }

  cout << count << endl;

  return 0;
}