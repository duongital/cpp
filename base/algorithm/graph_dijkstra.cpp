#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 10;
const int INF = 1e9;

vector<vector<pii>> graph(MAX, vector<pii>());
vector<int> dist(MAX, INF);
int path[MAX];

struct option {
  bool operator()(const pii &a, const pii &b) const {
    return a.second > b.second;
  }
};

void Dijkstra(int s) {
  priority_queue<pii, vector<pii>, option> pq;
  pq.push(make_pair(s, 0));
  dist[0] = 0;
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
  int n, s, t;
  cin >> n;
  s = 0;
  t = 4;
  int d = 0;
  // input using adjacency matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> d;
      if (d > 0) graph[i].push_back(make_pair(j, d));
    }
  }
  Dijkstra(s);
  // int ans = dist[t];
  // cout << ans << endl;
  for (auto i : dist) cout << i << " ";
  return 0;
}

/*
6
0 1 0 0 0 0
0 0 5 2 0 7
0 0 0 0 0 1
2 0 1 0 4 0
0 0 0 3 0 0
0 0 0 0 1 0
*/