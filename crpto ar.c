#include <stdio.h>
#include <stdbool.h>

#define N 10

bool isValidSolution(int s, int e, int n, int d, int m, int o, int r, int y) {
    int send = 1000 * s + 100 * e + 10 * n + d;
    int more = 1000 * m + 100 * o + 10 * r + e;
    int money = 10000 * m + 1000 * o + 100 * n + 10 * e + y;
    return (send + more == money);
}

void solve() {
    for (int s = 1; s < N; s++) {
        for (int e = 0; e < N; e++) {
            for (int n = 0; n < N; n++) {
                for (int d = 0; d < N; d++) {
                    for (int m = 1; m < N; m++) {
                        for (int o = 0; o < N; o++) {
                            for (int r = 0; r < N; r++) {
                                for (int y = 0; y < N; y++) {
                                    if (s != e && s != n && s != d && s != m && s != o && s != r && s != y &&
                                        e != n && e != d && e != m && e != o && e != r && e != y &&
                                        n != d && n != m && n != o && n != r && n != y &&
                                        d != m && d != o && d != r && d != y &&
                                        m != o && m != r && m != y &&
                                        o != r && o != y &&
                                        r != y) {
                                        if (isValidSolution(s, e, n, d, m, o, r, y)) {
                                            printf("SEND = %d, MORE = %d, MONEY = %d\n",
                                                    1000 * s + 100 * e + 10 * n + d,
                                                    1000 * m + 100 * o + 10 * r + e,
                                                    10000 * m + 1000 * o + 100 * n + 10 * e + y);
                                            return;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("No solution found\n");
}

int main() {
    solve();
    return 0;
}
