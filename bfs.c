#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int q[20], top = -1, front = -1, rear = -1, a[20][20], vis[20], stack[20];
void add(int item);
int rmove();
void bfs(int s, int n);

void main() {
    int n, i, s, ch, j;
    char c, dummy;
    system("cls");

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
	for (j = 1; j <= n; j++) {
	    printf("Enter 1 if vertex %d has an edge with vertex %d, else 0: ", i, j);
	    scanf("%d", &a[i][j]);
	}
    }
    printf("The adjacency matrix is:\n");
    for (i = 1; i <= n; i++) {
	for (j = 1; j <= n; j++) {
	    printf("%d ", a[i][j]);
	}
	printf("\n");
    }
    do {
	for (i = 1; i <= n; i++) {
	    vis[i] = 0;
	}

	printf("\nEnter the source vertex: ");
	scanf("%d", &s);
	bfs(s, n);
	printf("\nDo you want to perform BFS again? (y/n): ");
	getch();
	scanf("%c", &c);

    } while (c == 'y' || c == 'Y');

    getch();
}
void bfs(int s, int n) {
    int p, i;

    add(s);
    vis[s] = 1;

    p = rmove();
    if (p != 0) {
	printf("%d ", p);
    }
    while (p != 0) {
	for (i = 1; i <= n; i++) {
	    if (a[p][i] != 0 && vis[i] == 0) {
		add(i);
		vis[i] = 1;
	    }
	}
	p = rmove();
	if (p != 0) {
	    printf("%d ", p);
	}
    }
}
void add(int item) {
    if (rear == 19) {
	printf("Queue full\n");
    } else {
	if (rear == -1) {
	    q[++rear] = item;
	    front++;
	} else {
	    q[++rear] = item;
	}
    }
}
int rmove() {
    int k;
    if (front > rear || front == -1) {
	return 0;
    } else {
	k = q[front++];
	return k;
    }
}
