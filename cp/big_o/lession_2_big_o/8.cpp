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

  int i = 0, j = n - 1;
  int countAlice = 0, countBob = 0;
  int sumAlice = 0, sumBob = 0;
  while (i <= j) {
    if (sumAlice <= sumBob) {
      sumAlice += arr[i];
      i++;
      countAlice++;
    } else {
      sumBob += arr[j];
      j--;
      countBob++;
    }
  }
  cout << countAlice << " " << countBob << endl;

  return 0;
}