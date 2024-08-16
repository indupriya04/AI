#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define N 3
int rows[] = {1, 0, -1, 0};
int cols[] = {0, -1, 0, 1};
typedef struct {
    int matrix[N][N];
    int x, y; 
    int cost;
    int level;
    struct Node* parent;
} Node;

typedef struct {
    Node* heap[10000];
    int size;
} PriorityQueue;

// Function prototypes
void printMatrix(int matrix[N][N]);
int calculateCosts(int matrix[N][N], int final[N][N]);
Node* newNode(int matrix[N][N], int x, int y, int newX, int newY, int level, Node* parent, int final[N][N]);
void printPath(Node* root);
bool isSafe(int x, int y);
void push(PriorityQueue* pq, Node* node);
Node* pop(PriorityQueue* pq);
bool isEmpty(PriorityQueue* pq);
int compareNodes(Node* a, Node* b);
Node* newNode(int matrix[N][N], int x, int y, int newX, int newY, int level, Node* parent, int final[N][N]) {
    Node* node = (Node*)malloc(sizeof(Node));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            node->matrix[i][j] = matrix[i][j];

    int temp = node->matrix[x][y];
    node->matrix[x][y] = node->matrix[newX][newY];
    node->matrix[newX][newY] = temp;
    node->x = newX;
    node->y = newY;
    node->level = level;
    node->parent = parent;
    node->cost = calculateCosts(node->matrix, final) + level;

    return node;
}

int calculateCosts(int matrix[N][N], int final[N][N]) {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix[i][j] && matrix[i][j] != final[i][j])
                count++;
    return count;
}
void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
void printPath(Node* root) {
    if (root == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->matrix);
    printf("\n");
}
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}
void push(PriorityQueue* pq, Node* node) {
    pq->heap[pq->size] = node;
    pq->size++;
    int i = pq->size - 1;
    while (i > 0 && compareNodes(pq->heap[i], pq->heap[(i - 1) / 2]) < 0) {
        Node* temp = pq->heap[i];
        pq->heap[i] = pq->heap[(i - 1) / 2];
        pq->heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

Node* pop(PriorityQueue* pq) {
    if (pq->size == 0)
        return NULL;

    Node* root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int j = 2 * i + 1;
        if (j + 1 < pq->size && compareNodes(pq->heap[j], pq->heap[j + 1]) > 0)
            j++;
        if (compareNodes(pq->heap[i], pq->heap[j]) <= 0)
            break;
        Node* temp = pq->heap[i];
        pq->heap[i] = pq->heap[j];
        pq->heap[j] = temp;
        i = j;
    }

    return root;
}

bool isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int compareNodes(Node* a, Node* b) {
    return a->cost - b->cost;
}
void solve(int initial[N][N], int emptyX, int emptyY, int final[N][N]) {
    PriorityQueue pq;
    pq.size = 0;
    Node* root = newNode(initial, emptyX, emptyY, emptyX, emptyY, 0, NULL, final);
    push(&pq, root);

    while (!isEmpty(&pq)) {
        Node* minimum = pop(&pq);

        if (calculateCosts(minimum->matrix, final) == 0) {
            printPath(minimum);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = minimum->x + rows[i];
            int newY = minimum->y + cols[i];
            if (isSafe(newX, newY)) {
                Node* child = newNode(minimum->matrix, minimum->x, minimum->y, newX, newY, minimum->level + 1, minimum, final);
                push(&pq, child);
            }
        }
    }
}
int main() {
    int initial[N][N] = {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    int final[N][N] = {
        {1, 2, 3},
        {5, 8, 6},
        {0, 7, 4}
    };

    int emptyX = 1, emptyY = 2;
    solve(initial, emptyX, emptyY, final);
    return 0;
}
