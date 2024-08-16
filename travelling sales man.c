#include <stdio.h>
#include <limits.h>

#define V 4

int tsp(int graph[V][V], int s) {
    int vertex[V - 1];
    for (int i = 0, k = 0; i < V; i++) {
        if (i != s) {
            vertex[k++] = i;
        }
    }

    int min_path = INT_MAX;
    int permutation[V - 1];
    for (int i = 0; i < (1 << (V - 1)); i++) {
        for (int j = 0; j < (V - 1); j++) {
            permutation[j] = vertex[j];
        }

        for (int j = 0; j < (V - 1); j++) {
            for (int k = 0; k < (V - 1); k++) {
                if ((i >> k) & 1) {
                    int temp = permutation[j];
                    permutation[j] = permutation[k];
                    permutation[k] = temp;
                }
            }
        }

        int current_pathweight = 0;
        int k = s;
        for (int j = 0; j < (V - 1); j++) {
            current_pathweight += graph[k][permutation[j]];
            k = permutation[j];
        }
        current_pathweight += graph[k][s];

        if (current_pathweight < min_path) {
            min_path = current_pathweight;
        }
    }

    return min_path;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int s = 0;
    printf("Minimum cost: %d\n", tsp(graph, s));
    return 0;
}
