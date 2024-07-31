#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000 + 1;
int V, E;
vector<int> graph[MAX];
bool visited[MAX];
int path[MAX];
int dist[MAX];

void DFS(int s) {
  visited[s] = true;
  stack<int> stk;
  stk.push(s);

  while (!stk.empty()) {
    int u = stk.top();
    stk.pop();

    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if (!visited[v]) {
        visited[v] = true;
        path[v] = u;
        stk.push(v);
        dist[v] = dist[u] + 1;
      }
    }
  }
}

int main() {
  int N, Q;
  cin >> N;
  Q = N - 1;
  while (Q--) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // reset graph
  for (int i = 0; i < MAX; i++) {
    visited[i] = false;
    path[i] = -1;
    dist[i] = 0;
  }

  DFS(1);

  int ans, minDist = 1e9;
  int x;
  cin >> x;
  while (x--) {
    int girl;
    cin >> girl;
    if (dist[girl] < minDist || dist[girl] == minDist && ans > girl) {
      minDist = dist[girl];
      ans = girl;
    }
  }
  cout << ans << endl;
  return 0;
}