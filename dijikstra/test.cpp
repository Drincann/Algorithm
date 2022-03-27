
#include <iostream>
#include "./dijikstra.cpp"
int main() {
    int n = 6;
    init(n);
    graph[1][2] = graph[2][1] = 15;
    graph[1][5] = graph[5][1] = 5;
    graph[5][4] = graph[4][5] = 2;
    graph[2][4] = graph[4][2] = 4;
    graph[5][6] = graph[6][5] = 6;
    graph[4][6] = graph[6][4] = 1;
    graph[2][3] = graph[3][2] = 10;
    graph[3][6] = graph[6][3] = 3;
    diji(n, 1);
    for (int i = 1; i <= n; ++i) {
        std::cout << "to " << i << ": " << dist[i] << "; path: " << path[i]
                  << endl;
    }

    return 0;
}