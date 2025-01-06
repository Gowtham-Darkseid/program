#include<stdio.h>
#include<conio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}


int knapsack(int w, int wt[], int val[], int n)
{
    if (n == 0 || w == 0)
    {
	return 0;
    }

    if (wt[n-1] > w)
    {
	return knapsack(w, wt, val, n-1);
    }
    else
    {
      return max(val[n-1] + knapsack(w - wt[n-1], wt, val, n-1),
	    knapsack(w, wt, val, n-1));
    }
}
int main()
{
    int val[] = {20, 25, 40};
    int wt[] = {25, 20, 30};
    int w = 50;
    int n = sizeof(val) / sizeof(val[0]);
    clrscr();
    printf("Knapsack Problem\n");
    printf("The Solution is%d", knapsack(w, wt, val, n));
    getch();
    return 0;
}
