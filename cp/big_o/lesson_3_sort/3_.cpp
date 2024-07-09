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
    arrClone[i] = arrClone[i] - arr[i];
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arrClone[i] != 0) count++;

    if (arrClone[i] != 0 && start == 0) {
      start = i;
      end = i;
    } else if (arrClone[i] != 0) {
      end++;
    } else if (i + 1 < n && arrClone[i] == 0 && arrClone[i + 1] != 0) {
      end++;
    }
  }

  if (count % 2 == 1) {
    cout << "no" << endl;
  } else {
    cout << "yes" << endl;
    cout << start + 1 << " " << end + 1 << endl;
  }

  return 0;
}