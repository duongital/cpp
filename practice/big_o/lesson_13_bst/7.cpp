#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  getchar();
  getchar();
  while (t--) {
    map<string, int> record;
    string tree;
    int n = 0;
    while (getline(cin, tree)) {
      if (tree.compare("") == 0) break;
      record[tree]++;
      n++;
    }
    for (const auto& e : record) {
      cout << e.first << " " << fixed << setprecision(4) << 100.0 * e.second / n
           << endl;
    }
  }
  return 0;
}