#include <stdio.h>
#include <conio.h>
void main() {
    int a[2][2], b[2][2], c[2][2], i, j,n=2;
    int m1, m2, m3, m4, m5, m6, m7;
    clrscr();
    // Input Matrix A
    printf("Enter the elements for Matrix A (2x2):\n");
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    scanf("%d", &a[i][j]);
	}
    }

    // Input Matrix B
    printf("\nEnter the elements for Matrix B (2x2):\n");
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    scanf("%d", &b[i][j]);
	}
    }

    // Strassen's Multiplication
    m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    m2 = (a[1][0] + a[1][1]) * b[0][0];
    m3 = a[0][0] * (b[0][1] - b[1][1]);
    m4 = a[1][1] * (b[1][0] - b[0][0]);
    m5 = (a[0][0] + a[0][1]) * b[1][1];
    m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
    printf("\n%d\t%d\t%d\t%d\n",m1,m4,m5,m7);
    // Construct Resultant Matrix C
    c[0][0] = m1 + m4 - m5 + m7;
    c[0][1] = m3 + m5;
    c[1][0] = m2 + m4;
    c[1][1] = m1 - m2 + m3 + m6;

    // Print Resultant Matrix
    printf("Multiplication Result (Matrix C):\n");
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    printf("%d\t", c[i][j]);
	}
	printf("\n");
    }
    getch();
}
