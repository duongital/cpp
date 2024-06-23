#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> coins = {1, 2, 5};  // Example coins
  int n = 11;                     // Target sum
  vector<int> value(n + 1, INT_MAX);

  value[0] = 0;
  for (int x = 1; x <= n; x++) {
    for (auto c : coins) {
      if (x - c >= 0) {
        value[x] = min(value[x], value[x - c] + 1);
      }
    }
  }

  // If value[n] is still INT_MAX, it's not possible to make the sum n
  if (value[n] == INT_MAX) {
    cout << "It's not possible to make the sum " << n
         << " with the given coins." << endl;
  } else {
    cout << "Minimum coins required is " << value[n] << endl;
  }

  return 0;
}
