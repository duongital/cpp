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

  vector<int> arrClone = arr;

  sort(arrClone.begin(), arrClone.end());

  int start = 0, end = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] != arrClone[i]) {
      start = i;
      break;
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] != arrClone[i]) {
      end = i;
      break;
    }
  }

  for (int i = start, j = end; i < j; i++, j--) {
    swap(arr[i], arr[j]);
  }

  if (arr == arrClone) {
    cout << "yes" << endl;
    cout << start + 1 << " " << end + 1;
  } else {
    cout << "no" << endl;
  }

  return 0;
}