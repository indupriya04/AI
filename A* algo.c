#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COL 10

typedef struct Node {
    struct Node* parent;
    int position[2];
    int g, h, f;
} Node;

Node* createNode(Node* parent, int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->parent = parent;
    node->position[0] = x;
    node->position[1] = y;
    node->g = node->h = node->f = 0;
    return node;
}

int isValid(int maze[ROW][COL], int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 0);
}

int isInList(Node* list[], int size, Node* node) {
    for (int i = 0; i < size; i++) {
        if (list[i]->position[0] == node->position[0] &&
            list[i]->position[1] == node->position[1]) {
            return 1;
        }
    }
    return 0;
}

void astar(int maze[ROW][COL], int start[2], int end[2]) {
    Node* openList[ROW * COL];
    Node* closedList[ROW * COL];
    int openListSize = 0, closedListSize = 0;

    Node* startNode = createNode(NULL, start[0], start[1]);
    Node* endNode = createNode(NULL, end[0], end[1]);

    openList[openListSize++] = startNode;

    while (openListSize > 0) {
        Node* currentNode = openList[0];
        int currentIndex = 0;

        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->f < currentNode->f) {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        for (int i = currentIndex; i < openListSize - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openListSize--;

        closedList[closedListSize++] = currentNode;

        if (currentNode->position[0] == endNode->position[0] &&
            currentNode->position[1] == endNode->position[1]) {
            Node* path[ROW * COL];
            int pathSize = 0;
            Node* pathNode = currentNode;
            while (pathNode != NULL) {
                path[pathSize++] = pathNode;
                pathNode = pathNode->parent;
            }
            printf("Path:\n");
            for (int i = pathSize - 1; i >= 0; i--) {
                printf("(%d, %d) ", path[i]->position[0], path[i]->position[1]);
            }
            printf("\n");
            return;
        }

        int directions[8][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

        for (int i = 0; i < 8; i++) {
            int newX = currentNode->position[0] + directions[i][0];
            int newY = currentNode->position[1] + directions[i][1];

            if (isValid(maze, newX, newY)) {
                Node* neighbor = createNode(currentNode, newX, newY);

                if (isInList(closedList, closedListSize, neighbor)) {
                    free(neighbor);
                    continue;
                }

                neighbor->g = currentNode->g + 1;
                neighbor->h = abs(neighbor->position[0] - endNode->position[0]) +
                              abs(neighbor->position[1] - endNode->position[1]);
                neighbor->f = neighbor->g + neighbor->h;

                if (!isInList(openList, openListSize, neighbor)) {
                    openList[openListSize++] = neighbor;
                } else {
                    free(neighbor);
                }
            }
        }
    }
    printf("No path found\n");
}

int main() {
    int maze[ROW][COL] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int start[2] = {0, 0};
    int end[2] = {7, 6};

    astar(maze, start, end);

    return 0;
}
