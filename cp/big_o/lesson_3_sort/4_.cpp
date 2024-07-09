#include <bits/stdc++.h>

using namespace std;

// bool compare1(int& a[2], int& b[2]) {
//   if (a[0] < b[0]) return true;
//   return false;
// }

bool callback(vector<int> a, vector<int> b) {
  if (a[0] > b[0]) return true;
  return false;
}

int main() {
  int n;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    arr.push_back(e);
  }

  vector<vector<int>> temp;
  for (int i = 0; i < n; i++) {
    vector<int> element = {arr[i], i};
    temp.push_back(element);
  }

  sort(temp.begin(), temp.end(), callback);

  for (int i = 0; i < temp.size(); i++) {
    for (int e : temp[i]) {
      cout << e << " ";
    }
    cout << endl;
  }

  return 0;
}