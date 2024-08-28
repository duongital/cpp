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

  int minValue = INT_MIN;
  for (int i = 0; i < n; i++) {
    int j = i;
    int minTemp = arr[j];
    while (j + 1 < n && abs(arr[j + 1] - minTemp) <= 1) {
      j++;
      minTemp = min(minTemp, arr[j]);
    }
    minValue = max(minValue, j - i + 1);
  }

  cout << minValue << endl;

  return 0;
}