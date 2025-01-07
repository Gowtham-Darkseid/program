#include <stdio.h>
#include <conio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost, cost[10][10];

void main() {
    clrscr();
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    
    printf("\nEnter the adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) {
                cost[i][j] = 999;  // Set 0 cost to a large number to avoid selecting 0 as a valid edge
            }
        }
    }

    visited[1] = 1;  // Start from the first node

    printf("\n");

    while(ne < n) {
        // Find the minimum cost edge
        for(i = 1, min = 999; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(cost[i][j] < min) {
                    if(visited[i] != 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        // If either of the nodes is not visited, include this edge in the MST
        if(visited[u] == 0 || visited[v] == 0) {
            printf("\nEdge%d: (%d %d) cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;  // Mark the node as visited
        }
        
        cost[a][b] = cost[b][a] = 999;  // Set the selected edge to a large number to avoid considering it again
    }

    printf("\nMinimum cost = %d", mincost);
    getch();
}
