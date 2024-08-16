#include <stdio.h>
#include <stdbool.h>

#define START_M 3
#define START_C 3
#define BOAT_CAPACITY 1

int actions[5][3] = {
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 1},
    {2, 0, 1},
    {0, 2, 1}
};

bool is_legal(int state[3]) {
    return (state[0] >= 0 && state[0] <= START_M &&
            state[1] >= 0 && state[1] <= START_C);
}

bool is_bank_safe(int bank[2]) {
    return !(bank[1] > bank[0] && bank[0] != 0);
}

bool is_state_safe(int state[3]) {
    int other_bank[3] = {
        START_M - state[0],
        START_C - state[1],
        1 - state[2]
    };
    return is_bank_safe(state) && is_bank_safe(other_bank);
}

void print_state(int state[3]) {
    printf("[%d, %d, %d]\n", state[0], state[1], state[2]);
}

bool in_path(int path[][3], int path_len, int state[3]) {
    for (int i = 0; i < path_len; i++) {
        if (path[i][0] == state[0] && path[i][1] == state[1] && path[i][2] == state[2]) {
            return true;
        }
    }
    return false;
}

void solve(int state[3], int path[][3], int path_len) {
    if (state[0] == 0 && state[1] == 0 && state[2] == 0) {
        print_state(state);
        return;
