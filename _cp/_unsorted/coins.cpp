#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> coins = {1, 2, 5};  // Example coins
  int n = 11;                     // Target sum
  vector<int> value(n + 1, INT_MAX);
  vector<int> first(n + 1, 0);

  value[0] = 0;
  for (int x = 1; x <= n; x++) {
    for (auto c : coins) {
      if (x - c >= 0 && value[x - c] + 1 < value[x]) {
        value[x] = value[x - c] + 1;
        first[x] = c;
      }
    }
  }

  // If value[n] is still INT_MAX, it's not possible to make the sum n
  if (value[n] == INT_MAX) {
    cout << "It's not possible to make the sum " << n
         << " with the given coins." << endl;
  } else {
    cout << "Minimum coins required is " << value[n] << endl;
    // To print the coins used, you can backtrack from n using the first vector
    cout << "Coins used: ";
    for (int x = n; x > 0; x -= first[x]) {
      cout << first[x] << " ";
    }
  }

  return 0;
}
