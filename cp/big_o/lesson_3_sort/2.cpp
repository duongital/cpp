#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    arr.push_back(e);
  }

  sort(arr.begin(), arr.end());

  int x = arr[b] - arr[b - 1];
  cout << x << endl;

  return 0;
}