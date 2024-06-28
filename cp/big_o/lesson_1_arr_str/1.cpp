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
    if (arr[i] == 0) {
      count++;
    }
  }
  if (n > 1 && count == 1) {
    cout << "YES";
  } else if (n == 1 && count == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}