#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
int minimax(int curDepth, int nodeIndex, bool maxTurn, int scores[], int targetDepth) {
    if (curDepth == targetDepth) {
        return scores[nodeIndex];
    }

    if (maxTurn) {
        return max(minimax(curDepth + 1, nodeIndex * 2, false, scores, targetDepth),
                   minimax(curDepth + 1, nodeIndex * 2 + 1, false, scores, targetDepth));
    } else {
        return min(minimax(curDepth + 1, nodeIndex * 2, true, scores, targetDepth),
                   minimax(curDepth + 1, nodeIndex * 2 + 1, true, scores, targetDepth));
    }
}
int main() {
    int n;
    printf("Enter the number of scores (must be a power of 2): ");
    scanf("%d", &n);
    int scores[n]; 
    printf("Enter the scores:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]); 
    }
    int treeDepth = log2(n); 
    printf("The optimal value is : %d\n", minimax(0, 0, true, scores, treeDepth)); 
    return 0; 
}
