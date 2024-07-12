#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void streetParade(vector<int> arr) {
  stack<int> stk;
  int nextCar = 1;
  for (int thCar : arr) {
    stk.push(thCar);
    while (!stk.empty() && stk.top() == nextCar) {
      stk.pop();
      nextCar += 1;
    }
  }
  if (nextCar == arr.size() + 1) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}

int main() {
  while (true) {
    int n, e;
    vector<int> arr;
    cin >> n;
    if (n == 0) break;

    while (n--) {
      cin >> e;
      arr.push_back(e);
    }

    streetParade(arr);
  }
  return 0;
}