#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

typedef struct {
    int front, rear;
    int items[SIZE];
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

bool isQueueEmpty(Queue* q) {
    return q->rear < q->front;
}

void enqueue(Queue* q, int item) {
    q->items[++(q->rear)] = item;
}

int dequeue(Queue* q) {
    return q->items[(q->front)++];
}

void bfs(int graph[SIZE][SIZE], int start, bool visited[SIZE]) {
    Queue q;
    initQueue(&q);
    
    visited[start] = true;
    enqueue(&q, start);
    
    while (!isQueueEmpty(&q)) {
        int v = dequeue(&q);
        printf("%d ", v);
        
        for (int i = 0; i < SIZE; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int graph[SIZE][SIZE] = {0};
    bool visited[SIZE] = {false};
    
    graph[5][3] = 1;
    graph[5][7] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[7][8] = 1;
    graph[4][8] = 1;
    
    printf("Following is the Breadth-First Search:\n");
    bfs(graph, 5, visited);
    
    return 0;
}
