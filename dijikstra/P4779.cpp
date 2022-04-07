/*
  洛谷 https://www.luogu.com.cn/problem/P4779
  链式前向星 dijikstra
*/
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;
constexpr int VERTEXN = 100010, EDGEN = 500010;

int dist[VERTEXN];
int vis[VERTEXN];

struct vertex {
    int id, dist;
};

bool operator<(const vertex& l, const vertex& r) {
    return l.dist > r.dist;
}

int edgeid = 0;
int head[VERTEXN];
struct edge {
    int to, next, w;
} edges[EDGEN];

void add(int u, int v, int w) {
    edges[++edgeid].to = v;
    edges[edgeid].w = w;
    edges[edgeid].next = head[u];
    head[u] = edgeid;
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
        for (int curredge = head[currVertex.id]; curredge;
             curredge = edges[curredge].next) {
            int adj = edges[curredge].to;
            if (dist[adj] > dist[currVertex.id] + edges[curredge].w) {
                dist[adj] = dist[currVertex.id] + edges[curredge].w;
                if (!vis[adj]) {
                    q.push((vertex){adj, dist[adj]});
                }
            }
        }
    }
}

int main() {
    int vertexlen, edgelen, start;
    cin >> vertexlen >> edgelen >> start;
    for (int i = 1; i <= vertexlen; ++i) {
        dist[i] = 0x7fffffff;
    }

    while (edgelen--) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        add(v1, v2, w);
    }
    dij(start);
    for (int i = 1; i <= vertexlen; ++i) {
        cout << dist[i] << " ";
    }
    return 0;
}