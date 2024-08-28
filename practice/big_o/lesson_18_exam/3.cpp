// Ubiquitous Religions
// union find disjoint set to connect groups
// count groups is the answer

#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000;
int parent[MAX], ranks[MAX], ans;

void makeSet(int x) {
  parent[x] = x;
  ranks[x] = 0;
}

int unionFind(int x) {
  if (parent[x] != x) parent[x] = unionFind(parent[x]);
  return parent[x];
}

void unionDisjointSet(int &x, int &y) {
  int PX = unionFind(x), PY = unionFind(y);
  if (PX == PY) return;
  ans--;
  if (ranks[PX] > ranks[PY])
    parent[PY] = PX;
  else {
    parent[PX] = PY;
    if (ranks[PX] == ranks[PY]) ranks[PY]++;
  }
}

int main() {
  int tc = 1, n, m, x, y;

  while (true) {
    cin >> n >> m;
    if (n == 0) break;

    for (int i = 0; i < n; i++) makeSet(i);

    ans = n;
    for (int i = 0; i < m; i++) {
      cin >> x >> y;
      unionDisjointSet(x, y);
    }

    cout << "Case " << tc++ << ": " << ans << endl;
  }

  return 0;
}