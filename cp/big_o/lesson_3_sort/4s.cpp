#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  const int MAX = 2005;
  int ranked[MAX] = {0};
  int n, rating;
  cin >> n;
  vector<int> ratings(n), sorted_ratings(n);

  for (int i = 0; i < n; i++) {
    cin >> rating;
    ratings[i] = sorted_ratings[i] = rating;
  }

  sort(sorted_ratings.begin(), sorted_ratings.end(), greater<int>());

  for (int i = 0; i < n; i++) {
    rating = sorted_ratings[i];

    if (!ranked[rating]) {
      ranked[rating] = i + 1;
    }
  }

  for (int& rating : ratings) {
    cout << ranked[rating] << " ";
  }

  return 0;
}
