#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
const int INF = 1e9;

struct Edge {
  int source, target, weight;
  Edge(int source = 0, int target = 0, int weight = 0) {
    this->source = source;
    this->target = target;
    this->weight = weight;
  }
};

vector<int> dist(MAX, INF);
vector<int> path(MAX, -1);
vector<Edge> graph;
int n, m;

bool BellmanFord(int s) {
  int u, v, w;
  dist[s] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      u = graph[j].source;
      v = graph[j].target;
      w = graph[j].weight;
      if (dist[u] != INF && (dist[u] + w < dist[v])) {
        dist[v] = dist[u] + w;
        path[v] = u;
      }
    }
  }

  // check negative cycle
  for (int i = 0; i < m; i++) {
    u = graph[i].source;
    v = graph[i].target;
    w = graph[i].weight;
    if (dist[u] != INF && (dist[u] + w < dist[v])) {
      return false;
    }
  }
  return true;
}

int main() {
  int s, t, u, v, w;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    graph.push_back(Edge(u, v, w));
  }
  s = 0;
  t = 4;
  bool res = BellmanFord(s);
  if (res == false) {
    cout << "has negative cycle" << endl;
  } else {
    cout << dist[t] << endl;
  }
  return 0;
}