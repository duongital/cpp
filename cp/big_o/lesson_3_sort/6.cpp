#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    arr.push_back(e);
  }

  sort(arr.begin(), arr.end());

  int count = 1;
  int maximum = 1;
  int temp = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1]) {
      temp++;
      maximum = max(maximum, temp);
    } else {
      count++;
      maximum = max(maximum, temp);
      temp = 1;
    }
  }

  cout << maximum << " " << count << endl;

  return 0;
}