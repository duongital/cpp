#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 501;
const int INF = 1e9;

vector<vector<pii>> graph(MAX, vector<pii>());
vector<int> dist(MAX, INF);
int path[MAX];

struct MinHeap {
  bool operator()(const pii &a, const pii &b) { return a.second > b.second; }
};

void Dijkstra(int s) {
  priority_queue<pii, vector<pii>, MinHeap> pq;
  pq.push(make_pair(s, 0));
  dist[s] = 0;
  while (!pq.empty()) {
    pii top = pq.top();
    pq.pop();
    int u = top.first;
    int w = top.second;

    for (int i = 0; i < graph[u].size(); i++) {
      pii neighbor = graph[u][i];
      if (w + neighbor.second < dist[neighbor.first]) {
        dist[neighbor.first] = w + neighbor.second;
        pq.push(make_pair(neighbor.first, dist[neighbor.first]));
        path[neighbor.first] = u;
      }
    }
  }
}

int main() {
  int V, exit, time, t;
  cin >> V >> exit >> time >> t;
  while (t--) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
  }

  int result = 0;
  for (int i = 1; i <= V; i++) {
    dist = vector<int>(MAX, INF);
    Dijkstra(i);
    if (dist[exit] <= time) result++;
  }

  cout << result << endl;
  return 0;
}