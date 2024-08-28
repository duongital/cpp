#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 100;
const int INF = 1e9;

vector<vector<pii>> graph(MAX, vector<pii>());
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, M;

struct MinHeap {
  bool operator()(const pii &a, const pii &b) { return a.second > b.second; }
};

void printMST() {
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (path[i] == -1) continue;
    ans += dist[i];
    cout << path[i] << " - " << " : " << dist[i] << endl;
  }
  cout << "weight of MST: " << ans << endl;
}

void prims(int src) {
  priority_queue<pii, vector<pii>, MinHeap> pq;
  pq.push(make_pair(src, 0));
  while (!pq.empty()) {
    int u = pq.top().first;
    pq.pop();
    visited[u] = true;

    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i].first;
      int w = graph[u][i].second;
      if (!visited[v] && dist[v] > w) {
        dist[v] = w;
        pq.push(make_pair(v, w));
        path[v] = u;
      }
    }
  }
}

int main() {
  int u, v, w;
  cin >> N >> M;
  memset(path, -1, sizeof(path));  // set all path member to -1
  for (int i = 0; i < M; i++) {
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }

  int s = 0;
  prims(s);
  printMST();
  return 0;
}