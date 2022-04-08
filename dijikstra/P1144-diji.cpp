/*
  洛谷 https://www.luogu.com.cn/problem/P1144
  数组 无权 dijikstra
*/
#define N 1000010
// #define M 2000010
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> mp[N];
struct vertex {
  int id, dist;
};
bool operator<(const vertex& l, const vertex& r) {
  return l.dist > r.dist;
}
int dist[N];
int c[N];
int vis[N];
#define mod 100003
void diji() {
  priority_queue<vertex> q;
  q.push((vertex){1, 0});
  c[1] = 1;
  dist[1] = 0;
  while (!q.empty()) {
    vertex currv = q.top();
    q.pop();
    int u = currv.id;
    if (vis[u]) {
      continue;
    }
    vis[u] = true;
    for (int v : mp[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        c[v] = c[u];
        if (!vis[v])
          q.push((vertex){v, dist[v]});
      } else if (dist[v] == dist[u] + 1) {
        c[v] = (c[v] + c[u]) % mod;
      }
    }
  }
}
#include <cstring>
int main() {
  memset(dist, 0x7f, N);
  int vln, eln;
  cin >> vln >> eln;
  while (eln--) {
    int u, v;
    cin >> u >> v;
    mp[u].push_back(v);
    mp[v].push_back(u);
  }
  diji();
  for (int i = 1; i <= vln; ++i) {
    cout << c[i] << endl;
  }
  return 0;
}