#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_POINTS 1000
// Function to calculate Manhattan distance
int manhattanDistance(int x1, int y1, int x2, int y2) {
 return abs(x1 - x2) + abs(y1 - y2);
}
// Function to find the minimum cost to connect all points using Prim's algorithm
int minCostConnectPoints(int points[][2], int pointsSize) {
 int minCost = 0;
 int visited[MAX_POINTS] = {0};
 int minDist[MAX_POINTS];
 for (int i = 0; i < pointsSize; i++) {
 minDist[i] = INT_MAX;
 }
 minDist[0] = 0; // Start with the first point
 for (int i = 0; i < pointsSize; i++) {
 int u = -1;
 // Find the point with the smallest distance that is not visited
 for (int j = 0; j < pointsSize; j++) {
 if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
 u = j;
 }
 }
 visited[u] = 1;
 minCost += minDist[u];
 // Update the distances of the remaining points
 for (int v = 0; v < pointsSize; v++) {
 if (!visited[v]) {
 int dist = manhattanDistance(
 points[u][0], points[u][1],
 points[v][0], points[v][1]
 );
 if (dist < minDist[v]) {
 minDist[v] = dist;
 }
 }
 }
 }
 return minCost;
}
int main() {
 int points[][2] = {
 {0, 0},
 {2, 2},
 {3, 10},
 {5, 2},
 {7, 0}
 };
 int pointsSize = sizeof(points) / sizeof(points[0]);
 int result = minCostConnectPoints(points, pointsSize);
 printf("Minimum cost to connect all points: %d\n", result);
 return 0;
}
