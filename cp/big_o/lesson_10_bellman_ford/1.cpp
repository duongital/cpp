#include <bits/stdc++.h>

using namespace std;
const int MAX = 1001;
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
int V, E;

bool BellmanFord(int s) {  // check negative cycle
  int u, v, w;
  dist[s] = 0;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < E; j++) {
      u = graph[j].source;
      v = graph[j].target;
      w = graph[j].weight;
      if (dist[u] != INF && (dist[u] + w < dist[v])) {
        dist[v] = dist[u] + w;
        path[v] = u;
      }
    }
  }

  for (int i = 0; i < E; i++) {
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
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> V >> E;

    // reset graph, path, dist
    graph.clear();
    dist = vector<int>(MAX, INF);
    path = vector<int>(MAX, -1);
    int i = E;
    while (i--) {
      int u, v, w;
      cin >> u >> v >> w;
      graph.push_back(Edge(u, v, w));
    }
    bool canNotBack = BellmanFord(0);
    if (canNotBack) {
      cout << "not possible" << endl;
    } else {
      cout << "possible" << endl;
    }
  }
  return 0;
}