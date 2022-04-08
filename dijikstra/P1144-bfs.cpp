#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
constexpr int N = 100010, M = 200010;
vector<unordered_map<int, int>> mp;
int dist[N];
int vis[N];

struct vertex {
  int id, dist;
};

bool operator<(const vertex& l, const vertex& r) {
  return l.dist > r.dist;
}
void dij(int start) {
  priority_queue<vertex> q;

  q.push((vertex){start, 0});
  dist[start] = 0;

  while (!q.empty()) {
    const vertex currVertex = q.top();
    q.pop();
    if (vis[currVertex.id])
      continue;
    vis[currVertex.id] = true;
    const unordered_map<int, int>& adjMap = mp[currVertex.id];
    for (auto& adj : adjMap) {
      const int adjid = adj.first;
      const int w = adj.second;
      if (dist[adjid] > dist[currVertex.id] + w) {
        dist[adjid] = dist[currVertex.id] + w;
        if (!vis[adjid]) {
          q.push((vertex){adjid, dist[adjid]});
        }
      }
    }
  }
}

int main() {
  mp.resize(N);
  int vertexlen, edgelen, start;
  cin >> vertexlen >> edgelen >> start;
  for (int i = 1; i <= vertexlen; ++i) {
    dist[i] = 0x7fffffff;
  }
  while (edgelen--) {
    int v1, v2, w;
    cin >> v1 >> v2 >> w;
    mp[v1][v2] = w;
  }
  dij(start);
  for (int vertexId = 1; vertexId <= vertexlen; ++vertexId) {
    cout << dist[vertexId] << " ";
  }
  return 0;
}