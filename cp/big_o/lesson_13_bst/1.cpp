#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, x;
    scanf("%d %d", &n, &x);
    set<int> s;
    while (n--) {
      int e;
      scanf("%d", &e);
      s.insert(e);
    }
    if (s.size() == x) {
      printf("Good\n");
    } else if (s.size() < x) {
      printf("Bad\n");
    } else {
      printf("Average\n");
    }
  }
  return 0;
}