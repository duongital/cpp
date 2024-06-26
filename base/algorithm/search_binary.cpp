#include <bits/stdc++.h>

using namespace std;

void binarySearch(int arr[], int len, int target) {
  int low = 0;
  int high = len - 1;

  while (low < high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
      cout << "see you at: " << mid << endl;
    }

    if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << "nothing found" << endl;
}

int main() {
  int arr[] = {2, 3, 4, 10, 40};
  cout << arr << endl;
  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + n);

  cout << "arr: " << arr << endl;
  cout << "arr + n: " << arr + n << endl;
  binarySearch(arr, n, 4);

  return 0;
}