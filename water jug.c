#include <stdio.h>

#define MAX1 5
#define MAX2 7
#define FILL 4

void pour(int jug1, int jug2) {
    printf("%d\t%d\n", jug1, jug2);

    if (jug2 == FILL) {
        return;
    }
    if (jug2 == MAX2) {
        pour(0, jug1);
    } else if (jug1 != 0 && jug2 == 0) {
        pour(0, jug1);
    } else if (jug1 == FILL) {
        pour(jug1, 0);
    } else if (jug1 < MAX1) {
        pour(MAX1, jug2);
    } else if (jug1 < (MAX2 - jug2)) {
        pour(0, jug1 + jug2);
    } else {
        pour(jug1 - (MAX2 - jug2), MAX2);
    }
}

int main() {
    printf("JUG1\tJUG2\n");
    pour(0, 0);
    return 0;
}
