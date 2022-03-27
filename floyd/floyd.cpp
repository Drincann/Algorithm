#include <cstring>
#include <iostream>
#define N 3000
#define infi 0x7f7f7f7f

int dist[N][N];
int path[N][N];
using namespace std;

void init(int n) {
    memset(dist, 0x7f, sizeof(dist));
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }
}

void floyd(int vertexn) {
    for (int mid = 1; mid <= vertexn; ++mid) {
        for (int start = 1; start <= vertexn; ++start) {
            if (dist[start][mid] == infi)
                continue;
            for (int end = 1; end <= vertexn; ++end) {
                if (dist[mid][end] == infi)
                    continue;
                if (dist[start][end] > dist[start][mid] + dist[mid][end]) {
                    dist[start][end] = dist[start][mid] + dist[mid][end];
                    path[start][end] = mid;
                }
            }
        }
    }
}

void findpath(int start, int end) {
    if (start == end) {
        cout << start << " ";
        return;
    }
    findpath(start, path[start][end]);
    cout << end << " ";
}