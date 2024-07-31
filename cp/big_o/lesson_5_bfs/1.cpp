#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000 + 1;
int V, E;  // input using edge list

vector<int> graph[MAX];
bool visited[MAX];
int dist[MAX];

void BFS(int s) {
  queue<int> q;
  visited[s] = true;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
        dist[v] = dist[u] + 1;
      }
    }
  }
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> V >> E;

    // reset graph and related ds
    for (int i = 1; i <= MAX; i++) {
      visited[i] = false;
      dist[i] = 0;
      graph[i].clear();
    }
    int t = E;
    while (t--) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    int start;
    cin >> start;
    BFS(start);
    for (int i = 1; i <= V; i++) {
      if (i == start) {
        continue;
      }
      cout << (visited[i] ? dist[i] * 6 : -1) << " ";
    }
    cout << endl;
  }

  return 0;
}