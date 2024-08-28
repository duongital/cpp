// Learning Languages
// graph DFS using matrix to represent relationships
// can't use edge list to traverse

#include <bits/stdc++.h>

using namespace std;

int n, m;
bool Visited[100];
bool Grid[100][100];

void DFS(int start) {
  Visited[start] = true;
  for (int i = 0; i < n; i++) {
    if (!Visited[i]) {
      for (int j = 0; j < m; j++) {
        if (Grid[i][j] && Grid[start][j]) {
          DFS(i);
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;

  // reset variables
  memset(Visited, false, sizeof(Visited));
  memset(Grid, false, sizeof(Grid));

  // prepare Grid matrix
  bool allZero = true;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int tmp;
      cin >> tmp;
      // temp - 1: convert to based 0 index
      Grid[i][tmp - 1] = true;
      allZero = false;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!Visited[i]) {
      DFS(i);
      ans++;
    }
  }
  if (allZero)
    cout << ans << endl;
  else
    cout << ans - 1 << endl;
  return 0;
}