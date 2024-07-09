#include <bits/stdc++.h>

using namespace std;

bool callback(vector<int> a, vector<int> b) {
  if (a[0] < b[0]) {
    return true;
  } else if (a[0] > b[0]) {
    return false;
  } else if (a[1] < b[1]) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int t = 8;
  vector<vector<int>> arr;
  while (t--) {
    int x, y;
    cin >> x >> y;
    vector<int> temp = {x, y};
    arr.push_back(temp);
  }
  sort(arr.begin(), arr.end(), callback);

  cout << "---" << endl;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 2; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] &&
      arr[3][0] == arr[4][0] && arr[5][0] == arr[6][0] &&
      arr[6][0] == arr[7][0]) {
    if (arr[0][1] == arr[3][1] && arr[3][1] == arr[5][1] &&
        arr[1][1] == arr[6][1] && arr[2][1] == arr[4][1] &&
        arr[4][1] == arr[7][1]) {
      cout << "respectable" << endl;
    } else {
      cout << "ugly" << endl;
    }
  } else {
    cout << "ugly" << endl;
  }
  return 0;
}