#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void display(int room[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", room[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int room[SIZE][SIZE];
    int x, y, z = 0;
    
    srand(time(0));

    printf("All the rooms are dirty\n");
    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < SIZE; y++) {
            room[x][y] = 1;
        }
    }
    display(room);

    x = 0;
    y = 0;

    while (x < SIZE) {
        while (y < SIZE) {
            room[x][y] = rand() % 2;
            y++;
        }
        x++;
        y = 0;
    }
    printf("Before cleaning the room I detect all of these random dirts\n");
    display(room);

    x = 0;
    y = 0;
    while (x < SIZE) {
        while (y < SIZE) {
            if (room[x][y] == 1) {
                printf("Vacuum in this location now, %d %d\n", x, y);
                room[x][y] = 0;
                printf("Cleaned %d %d\n", x, y);
                z++;
            }
            y++;
        }
        x++;
        y = 0;
    }

    float performance = 100 - ((z / 16.0) * 100);
    printf("Room is clean now\n");
    display(room);
    printf("Performance = %.2f%%\n", performance);

    return 0;
}
