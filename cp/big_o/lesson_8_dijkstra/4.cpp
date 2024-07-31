#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 10000;
const int INF = 1e9;

vector<vector<pii>> graph(MAX, vector<pii>());
vector<int> dist(MAX, INF);
int path[MAX];
map<string, int> m;

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
    if (dist[u] != w) continue;

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
  int s;
  cin >> s;
  while (s--) {
    // reset graph
    graph = vector<vector<pii>>(MAX, vector<pii>());
    int result = INF;

    int n, oneWay, twoWay, start, end;
    cin >> n >> oneWay >> twoWay >> start >> end;

    while (oneWay--) {
      int u, v, w;
      cin >> u >> v >> w;
      graph[u].push_back(make_pair(v, w));
    }

    while (twoWay--) {
      int u, v, w;
      cin >> u >> v >> w;
      graph[u].push_back(make_pair(v, w));
      // reset dist
      dist = vector<int>(MAX, INF);
      Dijkstra(start);
      result = min(result, dist[end]);

      // pop back graph
      graph[u].pop_back();
    }

    if (result < INF) {
      cout << result << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}