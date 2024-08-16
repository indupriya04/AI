#include <stdio.h>

#define MAX 1000
#define MIN -1000

int minimax(int depth, int nodeIndex, int maximizingPlayer,
            int values[], int alpha, int beta) {
    if (depth == 3) {
        return values[nodeIndex];
    }
    
    if (maximizingPlayer) {
        int best = MIN;
        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i, 0, values, alpha, beta);
            best = (best > val) ? best : val;
            alpha = (alpha > best) ? alpha : best;
            
            if (beta <= alpha) {
                break;
            }
        }
        return best;
    } else {
        int best = MAX;
        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i, 1, values, alpha, beta);
            best = (best < val) ? best : val;
            beta = (beta < best) ? beta : best;
            
            if (beta <= alpha) {
                break;
            }
        }
        return best;
    }
}

int main() {
    int values[] = {3, 5, 6, 9, 1, 2, 0, -1};
    int numValues = sizeof(values) / sizeof(values[0]);
    int optimalValue = minimax(0, 0, 1, values, MIN, MAX);
    printf("The optimal value is: %d\n", optimalValue);
    return 0;
}
