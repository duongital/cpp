#include <bits/stdc++.h>
using namespace std;
const int MAX = 30005;

int parent[MAX], cnt[MAX], ranks[MAX];

int findSet(int u) {
  if (parent[u] != u) parent[u] = findSet(parent[u]);
  return parent[u];
}
void unionSet(int u, int v) {
  int up = findSet(u);
  int vp = findSet(v);

  if (up == vp) {
    return;
  }
  if (ranks[up] > ranks[vp]) {
    parent[vp] = up;
    cnt[up] += cnt[vp];
  } else if (ranks[up] < ranks[vp]) {
    parent[up] = vp;
    cnt[vp] += cnt[up];
  } else {
    parent[up] = vp;
    cnt[vp] += cnt[up];
    ranks[vp]++;
  }
}
void makeSet() {
  for (int i = 0; i < MAX; i++) {
    parent[i] = i;
    ranks[i] = 0;
    cnt[i] = 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int u, v, t, n, m;
  cin >> t;

  while (t--) {
    cin >> n >> m;

    makeSet();

    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      unionSet(u, v);
    }

    int res = -1;
    for (int i = 1; i <= n; i++) {
      res = max(res, cnt[i]);
    }
    cout << res << endl;
  }

  return 0;
}