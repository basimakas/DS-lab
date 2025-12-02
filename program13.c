#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999
#define SIZE 10

int main() {
    int cost[SIZE][SIZE], distance[SIZE], pred[SIZE];
    int visited[SIZE], count, mindst, nextnode, i, j;
    int startnode, n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INFINITY;
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &startnode);

    // Initialize arrays
    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    
    while (count < n - 1) {
        mindst = INFINITY;

       
        for (i = 0; i < n; i++) {
            if (distance[i] < mindst && !visited[i]) {
                mindst = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (mindst + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindst + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }

        count++;
    }

    
    for (i = 0; i < n; i++) {
        if (i != startnode) {
            printf("\nDistance of node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);

            j = i;
            while (j != startnode) {
                j = pred[j];
                printf(" <- %d", j);
            }
        }
    }

    return 0;
}

