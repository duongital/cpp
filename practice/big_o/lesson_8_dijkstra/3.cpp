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

    // input a number of cities
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      string city;
      cin >> city;
      m[city] = i;

      int p;
      cin >> p;
      while (p--) {
        int u, w;
        cin >> u >> w;
        graph[i].push_back(make_pair(u, w));
      }
    }

    int tc;
    cin >> tc;
    while (tc--) {
      string start, end;
      cin >> start >> end;

      // reset dist
      dist = vector<int>(MAX, INF);
      Dijkstra(m[start]);
      cout << dist[m[end]] << endl;
    }
  }
  return 0;
}