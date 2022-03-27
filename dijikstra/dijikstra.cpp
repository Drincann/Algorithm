#include <cstring>
#include <queue>
using namespace std;
#define N 3000
#define infi 0x7f7f7f7f
int dist[N];
int path[N];
int vis[N];
int graph[N][N];

struct vertex {
    int dist;
    int id;
};

bool operator<(const vertex& l, const vertex& r) {
    return l.dist > r.dist;
}

void init(int vertexn) {
    memset(dist, 0x7f, sizeof(dist));
    memset(graph, 0x7f, sizeof(graph));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= vertexn; ++i) {
        graph[i][i] = 0;
    }
}

void diji(int vertexn, int start) {
    priority_queue<vertex> q;
    q.push((vertex){0, start});
    dist[start] = 0;
    while (!q.empty()) {
        vertex currvertex = q.top();
        q.pop();
        if (vis[currvertex.id])
            continue;
        vis[currvertex.id] = 1;
        for (int adjvertex = 1; adjvertex <= vertexn; ++adjvertex) {
            if (graph[currvertex.id][adjvertex] == infi)
                continue;
            if (dist[adjvertex] >
                dist[currvertex.id] + graph[currvertex.id][adjvertex]) {
                dist[adjvertex] =
                    dist[currvertex.id] + graph[currvertex.id][adjvertex];
                path[adjvertex] = currvertex.id;
                if (!vis[adjvertex])
                    q.push((vertex){dist[adjvertex], adjvertex});
            }
        }
    }
}
