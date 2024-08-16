#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6  // Number of nodes

void sortByDegree(int G[N][N], int degree[], int sortedNodes[], int *indices) {
    int _max, idx;
    for (int i = 0; i < N; i++) {
        _max = -1;
        idx = -1;
        for (int j = 0; j < N; j++) {
            if (indices[j] == -1 && degree[j] > _max) {
                _max = degree[j];
                idx = j;
            }
        }
        indices[idx] = i;
        sortedNodes[i] = idx;
    }
}

void printSolution(char nodes[], char colors[], int sortedNodes[]) {
    printf("Graph Coloring Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("Node %c = %s\n", nodes[sortedNodes[i]], colors[i] ? "Blue" : "Red");
    }
}

int main() {
    int G[N][N] = {
        {0, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 0, 1},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 1},
        {0, 1, 0, 1, 1, 0}
    };

    char nodes[N] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int degree[N];
    int sortedNodes[N];
    int indices[N];

    // Initialize degree array and indices
    for (int i = 0; i < N; i++) {
        degree[i] = 0;
        indices[i] = -1;
        for (int j = 0; j < N; j++) {
            degree[i] += G[i][j];
        }
    }

    // Sort nodes by degree
    sortByDegree(G, degree, sortedNodes, indices);

    // Color assignment
    char colors[N] = {'', '', '', '', '', ''};
    char colorOptions[4][10] = {"Blue", "Red", "Yellow", "Green"};

    for (int i = 0; i < N; i++) {
        int node = sortedNodes[i];
        int colorAssigned = 0;
        for (int c = 0; c < 4; c++) {
            int valid = 1;
            for (int j = 0; j < N; j++) {
                if (G[node][j] == 1 && colors[j] == colorOptions[c]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                colors[node] = colorOptions[c][0];
                colorAssigned = 1;
                break;
            }
        }
        if (!colorAssigned) {
            colors[node] = 'B'; // Default color if no valid option found
        }
    }
    printSolution(nodes, colors, sortedNodes);

    return 0;
}
