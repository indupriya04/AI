#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

void dfs(int graph[SIZE][SIZE], bool visited[], int node) {
    visited[node] = true;
    printf("%d\n", node);

    for (int i = 0; i < SIZE; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

int main() {
    int graph[SIZE][SIZE] = {0};
    bool visited[SIZE] = {false};
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][0] = 1;
    graph[3][1] = 1;
    graph[4][3] = 1;

    printf("Following is the Depth-First Search:\n");
    dfs(graph, visited, 0);

    return 0;
}
