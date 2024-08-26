#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 10000;
const int INF = 1e9;
vector<pii> graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N;

void PrintMST() {
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (path[i] == -1) continue;
    ans += dist[i];
  }
  cout << ans;
}

void Prims(int src) {
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0, src));
  dist[src] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i].first;
      int w = graph[u][i].second;
      if (!visited[v] && dist[v] > w) {
        dist[v] = w;
        pq.push(make_pair(w, v));
        path[v] = u;
      }
    }
  }
}

int main() {
  int M, u, v, w;
  cin >> N >> M;
  memset(path, -1, sizeof(path));
  int s = 0;
  for (int i = 0; i < M; i++) {
    cin >> u >> v >> w;
    s = u - 1;
    graph[u - 1].push_back(make_pair(v - 1, w));
    graph[v - 1].push_back(make_pair(u - 1, w));
  }

  Prims(s);
  PrintMST();
  return 0;
}